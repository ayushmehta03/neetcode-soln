from typing import List
from collections import deque

def count_components(n: int, edges: List[List[int]]) -> int:
    """
    Counts the number of connected components in an undirected graph.

    Args:
        n (int): Number of nodes.
        edges (List[List[int]]): List of undirected graph edges.

    Returns:
        int: The number of connected components.

    Explanation:
        - Each time a node is found that hasn't been visited yet,
          perform BFS from it and mark all reachable nodes;
          increment the component count.
        - Continue this for all nodes.
    """
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    visited = set()
    components = 0

    for start in range(n):
        if start not in visited:
            # Start BFS for this new component
            components += 1
            queue = deque([start])
            visited.add(start)
            while queue:
                node = queue.popleft()
                for neighbor in adj[node]:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append(neighbor)
    return components


def main():
    """
    Example usage and demonstration of count_components function.
    """
    # Example 1: Two components
    n1 = 5
    edges1 = [[0, 1], [1, 2], [3, 4]]
    print(count_components(n1, edges1))  # Output: 2

    # Example 2: Single component
    n2 = 4
    edges2 = [[0, 1], [1, 2], [2, 3]]
    print(count_components(n2, edges2))  # Output: 1

    # Example 3: No edges, all nodes disconnected
    n3 = 3
    edges3 = []
    print(count_components(n3, edges3))  # Output: 3

if __name__ == "__main__":
    main()
