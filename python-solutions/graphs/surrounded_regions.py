from typing import List

class Solution:
    """
    Solves the 'Surrounded Regions' problem.
    
    Problem Summary:
    Given a matrix `board` containing 'X' and 'O', capture all regions
    surrounded by 'X'. A region is captured by flipping all 'O's into 'X's
    in that surrounded region.
    
    Any 'O' on the border, or connected to a border 'O', should *not* be flipped.
    
    Method:
    1. Run DFS from border 'O' cells to mark safe regions (temporarily as 'T').
    2. Convert all remaining 'O' cells to 'X' (captured regions).
    3. Convert all 'T' cells back to 'O' (safe regions).
    """

    # Directions for traversing up, right, down, left
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]

    def solve(self, board: List[List[str]]) -> None:
        """
        Modifies the input board in-place to capture surrounded regions.
        """
        if not board or not board[0]:
            return

        m, n = len(board), len(board[0])

        # Step 1: Perform DFS for all border cells with 'O'
        for i in range(m):
            for j in range(n):
                if (i == 0 or i == m - 1 or j == 0 or j == n - 1) and board[i][j] == "O":
                    self.dfs(i, j, board)

        # Step 2: Convert interior 'O's to 'X's (captured)
        # Step 3: Convert temporary 'T's back to 'O's (safe)
        for i in range(m):
            for j in range(n):
                if board[i][j] == "O":
                    board[i][j] = "X"
                elif board[i][j] == "T":
                    board[i][j] = "O"

    def dfs(self, i: int, j: int, board: List[List[str]]) -> None:
        """
        Depth-First Search to mark all 'O's connected to border 'O' as 'T'.
        """
        board[i][j] = "T"

        for k in range(4):
            row, col = i + self.dx[k], j + self.dy[k]
            if 0 <= row < len(board) and 0 <= col < len(board[0]) and board[row][col] == "O":
                self.dfs(row, col, board)


def main():
    """
    Example usage of the Solution.solve() method.
    """
    board = [
        ['X', 'X', 'X', 'X'],
        ['X', 'O', 'O', 'X'],
        ['X', 'X', 'O', 'X'],
        ['X', 'O', 'X', 'X']
    ]

    print("Original Board:")
    for row in board:
        print(' '.join(row))

    sol = Solution()
    sol.solve(board)

    print("\nBoard After Capturing Regions:")
    for row in board:
        print(' '.join(row))


if __name__ == "__main__":
    main()
