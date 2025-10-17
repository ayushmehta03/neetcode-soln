from typing import List

def max_area_of_island(grid: List[List[int]]):
    
    m = len(grid)
    n = len(grid[0])
    
    max_area = 0
    vis = [[False]*n for _ in range(m)]
    
    for i in range(m):
        for j in range(n):
            if (grid[i][j] == 1 and not vis[i][j]):
                max_area = max(max_area, area_of_island(i,j,grid,vis))
    
    return max_area

def area_of_island(i: int, j: int, grid: List[List[int]], vis: List[List[bool]] ):
    
    if (i >= len(grid) or i < 0 or j >= len(grid[0]) or j < 0 or grid[i][j] == 0 or  vis[i][j]): return 0
    
    vis[i][j] = True
    
    return 1 + area_of_island(i-1,j,grid,vis) + area_of_island(i,j+1,grid,vis) + area_of_island(i+1,j,grid,vis) + area_of_island(i,j-1,grid,vis)


def main():
    grid = []
    
    m,n = map(int,input().split())
    
    for i in range(m):
        temp = list(map(int,input(f"enter {n} space-separated values for the {i}th row of the grid")))
        grid.append(temp)
        
    print(max_area_of_island(grid))

if __name__ == "__main__":
    main()
    
    
    