from collections import deque
import heapq


# ===========================
# Base Problem + Node Classes
# ===========================

class Problem:
    """
    Abstract base class for a problem.
    """
    def __init__(self, initial, goal=None):
        self.initial = initial
        self.goal = goal
    
    def actions(self, state):
        raise NotImplementedError

    def result(self, state, action):
        raise NotImplementedError
    
    def goal_test(self, state):
        return state == self.goal
    
    def path_cost(self, c, state1, action, state2):
        return c + 1
    


class Node:
    def __init__(self, state, parent=None, action=None, path_cost=0):
        self.state = state
        self.parent = parent
        self.action = action
        self.path_cost = path_cost
        self.depth = parent.depth + 1 if parent else 0

    def __repr__(self):
        return f"<Node {self.state}>"
    
    def __lt__(self, node):
        return self.state < node.state
    
    def expand(self, problem):
        """Return list of child nodes reachable from current node."""
        return [self.child_node(problem, action) for action in problem.actions(self.state)]
    
    def child_node(self, problem, action):
        next_state = problem.result(self.state, action)
        return Node(next_state, self, action, problem.path_cost(self.path_cost, self.state, action, next_state))
    
    def solution(self):
        """Return list of actions from root to this node"""
        return [node.action for node in self.path()[1:]]
    
    def path(self):
        node, path_back = self, []
        while node:
            path_back.append(node)
            node = node.parent
        return list(reversed(path_back))
    
    def __eq__(self, other):
        return isinstance(other, Node) and self.state == other.state
    
    def __hash__(self):
        return hash(self.state)
    


# ===========================
# Search Algorithms
# ===========================

def bfs_tree(problem):
    frontier = deque([Node(problem.initial)])
    while frontier:
        node = frontier.popleft()
        if problem.goal_test(node.state):
            return node
        frontier.extend(node.expand(problem))
    return None


def dfs_tree(problem):
    frontier = [Node(problem.initial)]
    while frontier:
        node = frontier.pop()
        if problem.goal_test(node.state):
            return node
        frontier.extend(node.expand(problem))
    return None


def bfs_graph(problem):
    start_node = Node(problem.initial)
    frontier = deque([start_node])
    explored = set([problem.initial])  

    while frontier:
        node = frontier.popleft()
        if problem.goal_test(node.state):
            return node
        for child in node.expand(problem):
            if child.state not in explored:
                explored.add(child.state)  
                frontier.append(child)
    return None


def dfs_graph(problem):
    frontier = [Node(problem.initial)]
    explored = set([problem.initial])
    while frontier:
        node = frontier.pop()
        if problem.goal_test(node.state):
            return node
        for child in node.expand(problem):
            if child.state not in explored:
                explored.add(child.state)
                frontier.append(child)
    return None


def ucs_graph(problem):
    start_node = Node(problem.initial)
    frontier = []
    heapq.heappush(frontier, (start_node.path_cost, start_node))
    explored = {}

    while frontier:
        current_cost, node = heapq.heappop(frontier)

        if problem.goal_test(node.state):
            return node

        if node.state in explored and explored[node.state] <= current_cost:
            continue

        explored[node.state] = current_cost

        for child in node.expand(problem):
            cost = child.path_cost
            if child.state not in explored or explored[child.state] > cost:
                heapq.heappush(frontier, (cost, child))

    return None


def depth_limited_search(node, problem, limit, explored):
    """DFS with a depth limit"""
    if problem.goal_test(node.state):
        return node
    elif limit == 0:
        return None
    else:
        explored.add(node.state)
        for child in node.expand(problem):
            if child.state not in explored:
                result = depth_limited_search(child, problem, limit - 1, explored)
                if result is not None:
                    return result
        return None


def iddfs(problem, max_depth=50):
    for depth in range(max_depth):
        explored = set()
        result = depth_limited_search(Node(problem.initial), problem, depth, explored)
        if result is not None:
            return result
    return None


# ===========================
# A* Search
# ===========================

def astar_search(problem, heuristic):
    start_node = Node(problem.initial)
    frontier = []
    heapq.heappush(frontier, (heuristic(start_node), start_node))
    explored = {start_node.state: 0}

    while frontier:
        f, node = heapq.heappop(frontier)

        if problem.goal_test(node.state):
            return node

        for child in node.expand(problem):
            g = child.path_cost
            h = heuristic(child)
            f = g + h

            if child.state not in explored or explored[child.state] > g:
                explored[child.state] = g
                heapq.heappush(frontier, (f, child))

    return None


# ===========================
# Eight Puzzle
# ===========================

class EightPuzzle(Problem):
    def __init__(self, initial, goal=(1,2,3,4,5,6,7,8,0)):
        if isinstance(initial, list) and isinstance(initial[0], list):
            initial = tuple(sum(initial, [])) 
        elif isinstance(initial, list): 
            initial = tuple(initial)
        super().__init__(initial, goal)

    def actions(self, state):
        index = state.index(0)
        moves = []
        row, col = divmod(index, 3)
        if row > 0: moves.append("UP")
        if row < 2: moves.append("DOWN")
        if col > 0: moves.append("LEFT")
        if col < 2: moves.append("RIGHT")
        return moves
    
    def result(self, state, action):
        index = state.index(0)
        row, col = divmod(index, 3)
        new_state = list(state)

        if action == "UP":
            swap_index = (row - 1) * 3 + col
        elif action == "DOWN":
            swap_index = (row + 1) * 3 + col
        elif action == "LEFT":
            swap_index = row * 3 + (col - 1)
        elif action == "RIGHT":
            swap_index = row * 3 + (col + 1)
        
        new_state[index], new_state[swap_index] = new_state[swap_index], new_state[index]
        return tuple(new_state)


def manhattan_distance(node):
    state = node.state
    distance = 0
    for i, tile in enumerate(state):
        if tile == 0: 
            continue
        goal_row, goal_col = divmod(tile - 1, 3)
        row, col = divmod(i, 3)
        distance += abs(row - goal_row) + abs(col - goal_col)
    return distance


# ===========================
# Grid Pathfinding
# ===========================

class GridPath(Problem):
    def __init__(self, initial, goal, grid):
        super().__init__(initial, goal)
        self.grid = grid
        self.rows = len(grid)
        self.cols = len(grid[0])

    def actions(self, state):
        x, y = state
        moves = []
        directions = [(0,1), (1,0), (0,-1), (-1,0)]  # Right, Down, Left, Up
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < self.rows and 0 <= ny < self.cols and self.grid[nx][ny] == 0:
                moves.append((dx, dy))
        return moves

    def result(self, state, action):
        x, y = state
        dx, dy = action
        return (x + dx, y + dy)


def manhattan_2d(node, goal):
    x1, y1 = node.state
    x2, y2 = goal
    return abs(x1 - x2) + abs(y1 - y2)


# ===========================
# MAIN DRIVER
# ===========================

if __name__ == "__main__":
    # --------- Eight Puzzle ---------
    print("==== Eight Puzzle with A* ====")
    initial = (1,2,3,0,4,6,7,5,8)
    problem = EightPuzzle(initial)

    solutionnode = astar_search(problem, heuristic=manhattan_distance)

    if solutionnode:
        print("Moves:", solutionnode.solution())
        print("Steps:", len(solutionnode.solution()))
        print("Path of states:")
        for n in solutionnode.path():
            print(n.state)
    else:
        print("No solution")

    # --------- Grid Pathfinding ---------
    print("\n==== Grid Pathfinding with A* ====")
    grid = [
        [0,0,0,1,0],
        [1,1,0,1,0],
        [0,0,0,0,0],
        [0,1,1,1,0],
        [0,0,0,1,0]
    ]
    start = (0,0)
    goal = (4,4)

    problem2 = GridPath(start, goal, grid)
    solutionnode2 = astar_search(problem2, heuristic=lambda n: manhattan_2d(n, goal))

    if solutionnode2:
        print("Path:", [n.state for n in solutionnode2.path()])
        print("Moves:", solutionnode2.solution())
        print("Steps:", len(solutionnode2.solution()))
    else:
        print("No path found")
