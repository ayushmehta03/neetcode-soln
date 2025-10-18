from typing import List

def numIslands(grid: List[List[str]]) -> int:
    """
    Counts the number of islands in a 2D grid using DFS.
    
    An island is surrounded by water ('0') and is formed by connecting adjacent lands ('1')
    horizontally or vertically. The function mutates the grid to mark visited land.

    Args:
        grid (List[List[str]]): 2D list of '1's (land) and '0's (water).
    
    Returns:
        int: The number of islands found in the grid.
    """
    rows, cols = len(grid), len(grid[0])

    def dfs(r, c):
        """
        Depth-First Search to mark all adjacent '1's as visited.

        Args:
            r (int): Current row.
            c (int): Current column.
        """
        # If out of bounds or at a water cell, return
        if (r < 0 or c < 0 or r == rows or c == cols or grid[r][c] == '0'):
            return

        grid[r][c] = '0'  # Mark current cell as visited (turn land into water)

        # Explore all four neighboring directions
        dfs(r + 1, c)  # Down
        dfs(r - 1, c)  # Up
        dfs(r, c + 1)  # Right
        dfs(r, c - 1)  # Left

    islands = 0
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == '1':
                islands += 1      # Found a new island
                dfs(r, c)         # Mark all cells in this island as visited
    
    return islands

def main():
    """
    Reads a grid from user input row by row (as strings of 0s and 1s), then prints the island count.
    """
    print("Enter the number of rows in the grid:")
    m = int(input())
    print("Enter the number of columns in the grid:")
    n = int(input())
    print("Enter the grid, one row per line using only '0' and '1':")
    grid = []
    for _ in range(m):
        # Each row is entered as e.g. '11000'
        row = list(input().strip())
        grid.append(row)
    print("Number of islands:", numIslands(grid))

if __name__ == "__main__":
    main()
