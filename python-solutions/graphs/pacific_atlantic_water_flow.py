from collections import deque

def bfs(starts, visited, heights): 
        """
        Breadth-first search (BFS) from given starting points. 
        Marks cells that can be reached based on height constraints.
        """
        queue = deque(starts)
        for i, j in starts:
            visited[i][j] = True

        while queue:
            i, j = queue.popleft()
            for di, dj in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                ni, nj = i + di, j + dj
                # Check bounds and height condition
                if (0 <= ni < len(heights) and 0 <= nj < len(heights[0]) and
                        not visited[ni][nj] and
                        heights[ni][nj] >= heights[i][j]):
                    visited[ni][nj] = True
                    queue.append((ni, nj))

def pacificAtlantic(heights):
    """
    Determines the coordinates in a matrix from which water can flow to both 
    the Pacific and Atlantic oceans.

    The Pacific touches the matrix's left and top edges, while the Atlantic 
    touches the right and bottom edges. Water can flow from a cell to a 
    neighboring cell (up, down, left, right) only if the neighboring cell's 
    height is less than or equal to the current cell's height.

    Args:
        heights (List[List[int]]): 2D list representing the height of each cell.

    Returns:
        List[List[int]]: List of coordinates [i, j] where water can flow to both oceans.
    """

    if not heights or not heights[0]:
        return []

    m, n = len(heights), len(heights[0])

    pacific = [[False] * n for _ in range(m)]
    atlantic = [[False] * n for _ in range(m)]

    # Starting cells adjacent to each ocean
    pacific_starts = [(i, 0) for i in range(m)] + [(0, j) for j in range(n)]
    atlantic_starts = [(i, n - 1) for i in range(m)] + [(m - 1, j) for j in range(n)]

    bfs(pacific_starts, pacific,heights)
    bfs(atlantic_starts, atlantic, heights)

    result = []
    for i in range(m):
        for j in range(n):
            if pacific[i][j] and atlantic[i][j]:
                result.append([i, j])

    return result


def main():
    """
    Demonstrates the use of the pacificAtlantic function
    with an example input.
    """
    # Example height matrix
    heights = [
        [1, 2, 2, 3, 5],
        [3, 2, 3, 4, 4],
        [2, 4, 5, 3, 1],
        [6, 7, 1, 4, 5],
        [5, 1, 1, 2, 4]
    ]

    # Compute cells that can reach both oceans
    result = pacificAtlantic(heights)

    print("Cells that can reach both the Pacific and Atlantic oceans:")
    for cell in result:
        print(cell)


if __name__ == "__main__":
    main()
