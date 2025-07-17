import sys

def main():
    data = sys.stdin.read().split()
    it = iter(data)
    n = int(next(it)); q = int(next(it))
    next_arr = [0] * n
    for i in range(n):
        x = int(next(it))
        next_arr[i] = x - 1

    color = [0] * n
    depth_arr = [-1] * n
    comp_id_arr = [-1] * n
    entry_node = [-1] * n
    index_in_cycle = [-1] * n
    cycle_length_dict = {}
    comp_counter = 0

    for i in range(n):
        if color[i] != 0:
            continue
        stack = []
        cur = i
        while color[cur] == 0:
            color[cur] = 1
            stack.append(cur)
            cur = next_arr[cur]
        
        if color[cur] == 2:
            for j in range(len(stack)-1, -1, -1):
                node = stack[j]
                depth_arr[node] = depth_arr[next_arr[node]] + 1
                comp_id_arr[node] = comp_id_arr[next_arr[node]]
                entry_node[node] = entry_node[next_arr[node]]
                color[node] = 2
        else:
            pos = stack.index(cur)
            cycle_nodes = stack[pos:]
            L = len(cycle_nodes)
            comp_id_here = comp_counter
            comp_counter += 1
            cycle_length_dict[comp_id_here] = L
            
            for idx, node in enumerate(cycle_nodes):
                color[node] = 2
                depth_arr[node] = 0
                comp_id_arr[node] = comp_id_here
                entry_node[node] = node
                index_in_cycle[node] = idx
                
            for j in range(pos-1, -1, -1):
                node = stack[j]
                color[node] = 2
                depth_arr[node] = depth_arr[stack[j+1]] + 1
                comp_id_arr[node] = comp_id_here
                entry_node[node] = cycle_nodes[0]

    LOG = (n).bit_length()
    up_table = [[0] * n for _ in range(LOG)]
    for i in range(n):
        up_table[0][i] = next_arr[i]
    
    for k in range(1, LOG):
        for i in range(n):
            up_table[k][i] = up_table[k-1][up_table[k-1][i]]
            
    def lift_node(node, k):
        for i in range(LOG):
            if k & (1 << i):
                node = up_table[i][node]
        return node

    out_lines = []
    for _ in range(q):
        a = int(next(it)); b = int(next(it))
        a0 = a-1; b0 = b-1
        if comp_id_arr[a0] != comp_id_arr[b0]:
            out_lines.append("-1")
        else:
            if depth_arr[b0] == 0:
                u = entry_node[a0]
                v = b0
                L_cycle = cycle_length_dict[comp_id_arr[a0]]
                idx_u = index_in_cycle[u]
                idx_v = index_in_cycle[v]
                d_cycle = idx_v - idx_u
                if d_cycle < 0:
                    d_cycle += L_cycle
                steps = depth_arr[a0] + d_cycle
                out_lines.append(str(steps))
            else:
                if depth_arr[a0] < depth_arr[b0]:
                    out_lines.append("-1")
                else:
                    k_steps = depth_arr[a0] - depth_arr[b0]
                    lifted_a = lift_node(a0, k_steps)
                    if lifted_a == b0:
                        out_lines.append(str(k_steps))
                    else:
                        out_lines.append("-1")
                        
    print("\n".join(out_lines))

if __name__ == '__main__':
    main()