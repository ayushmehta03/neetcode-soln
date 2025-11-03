from typing import List
from collections import deque

def valid_tree_bfs(n: int, edges: List[List[int]]) -> bool:
    """
    Determines if the undirected graph in the form of n nodes and a list of edges is a valid tree.

    Args:
        n (int): Number of nodes.
        edges (List[List[int]]): List of undirected edges connecting nodes.

    Returns:
        bool: True if the graph is a valid tree, False otherwise.

    Explanation:
        - A valid tree has n-1 edges and is fully connected (no cycles).
        - We use BFS for traversal, ensuring no cycles and full connectivity.
    """
    if len(edges) != n - 1:
        # A valid tree must have exactly n-1 edges
        return False

    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    visited = set()
    queue = deque([(0, -1)])  # (current_node, parent_node)
    visited.add(0)

    while queue:
        node, parent = queue.popleft()

        for neighbor in adj[node]:
            if neighbor == parent:
                continue  # Don't revisit the direct parent
            if neighbor in visited:
                # If we've already visited this node (and it isn't the parent), we found a cycle
                return False
            visited.add(neighbor)
            queue.append((neighbor, node))

    # All nodes must be visited for the graph to be fully connected
    return len(visited) == n


def main():
    """
    Example usage and testing of the valid_tree_bfs function.
    """
    # Example 1: Valid tree
    n1 = 5
    edges1 = [[0, 1], [0, 2], [0, 3], [1, 4]]
    print(valid_tree_bfs(n1, edges1))  # Output: True

    # Example 2: Not a tree (contains a cycle)
    n2 = 5
    edges2 = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
    print(valid_tree_bfs(n2, edges2))  # Output: False

    # Example 3: Not fully connected
    n3 = 4
    edges3 = [[0, 1], [2, 3]]
    print(valid_tree_bfs(n3, edges3))  # Output: False


if __name__ == "__main__":
    main()
