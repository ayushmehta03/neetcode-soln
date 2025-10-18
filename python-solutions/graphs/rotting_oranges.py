from typing import List
from collections import deque

def oranges_rotting(grid: List[List[int]]) -> int:
    """
    Finds the minimum number of minutes required for all fresh oranges to become rotten
    in a 2D grid, or returns -1 if not all fresh oranges can become rotten.

    Args:
        grid (List[List[int]]): 2D integer grid representing the state of each cell:
            0 = empty cell
            1 = fresh orange
            2 = rotten orange

    Returns:
        int: Minimum number of minutes to rot all fresh oranges, or -1 if impossible.

    Explanation:
        1. Use BFS to spread rot from rotten oranges (value 2) to adjacent fresh oranges (value 1).
        2. Track time with a queue that stores (row, col, minute) for each rotten orange being processed.
        3. Decrement fresh_count each time a fresh orange is rotted.
        4. The answer is the maximum number of minutes needed, or -1 if there are unreachable fresh oranges.
    """
    m, n = len(grid), len(grid[0])
    q = deque()
    fresh_count = 0

    # Initialize: Add all rotten oranges to the queue and count fresh ones
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 2:
                q.append((i, j, 0))
            elif grid[i][j] == 1:
                fresh_count += 1

    if fresh_count == 0:
        # All oranges are already rotten or empty
        return 0

    # Directions: up, right, down, left
    dr = [-1, 0, 1, 0]
    dc = [0, 1, 0, -1]
    minutes = 0

    # BFS to spread rot
    while q:
        r, c, t = q.popleft()
        minutes = max(minutes, t)
        for k in range(4):
            nrow, ncol = r + dr[k], c + dc[k]
            # Rot fresh orange if in bounds and still fresh
            if 0 <= nrow < m and 0 <= ncol < n and grid[nrow][ncol] == 1:
                grid[nrow][ncol] = 2
                q.append((nrow, ncol, t + 1))
                fresh_count -= 1

    return minutes if fresh_count == 0 else -1

def main():
    """
    Entry point for demo/testing.
    Prompts the user for grid size and grid values,
    then prints the minimum minutes required to rot all oranges.

    Example:
        Enter number of rows and columns: 3 3
        Enter grid values row by row (space-separated): 
        2 1 1
        1 1 0
        0 1 1
        Output: Minutes required to rot all oranges: 4

    Code Explanation:
        - This script reads a grid from user input, where each entry is 0, 1, or 2.
        - It then calls `oranges_rotting` to calculate how many minutes it would take
          for all fresh oranges to become rotten.
        - The BFS ensures all adjacent oranges are processed minute-by-minute, simulating the infection process.
    """
    print("Enter number of rows and columns:", end=" ")
    m, n = map(int, input().split())
    print("Enter grid values row by row (space-separated):")
    grid = []
    for i in range(m):
        row = list(map(int, input().split()))
        assert len(row) == n, "Each row should have exactly n elements."
        grid.append(row)

    result = oranges_rotting(grid)
    print("Minutes required to rot all oranges:", result)

if __name__ == "__main__":
    main()
