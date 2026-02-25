# Pseudocode for the DP transition
def solve(idx, lastB, lastC):
    if idx > n:
        return 0
    
    # Option 1: Skip the current room
    res = solve(idx + 1, lastB, lastC)
    
    # Option 2: Batman picks the room
    if Tag[idx] > Tag[lastB]:
        res = max(res, 1 + solve(idx + 1, idx, lastC))
        
    # Option 3: Catwoman picks the room
    if Tag[idx] < Tag[lastC]:
        res = max(res, 1 + solve(idx + 1, lastB, idx))
        
    return res