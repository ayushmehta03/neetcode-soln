from typing import List
from collections import deque

def find_redundant_connection(edges: List[List[int]]) -> List[int]:
    """
    Finds the redundant edge in an undirected graph that would cause a cycle.
    Assumes the input is a tree with one extra edge added.

    Args:
        edges (List[List[int]]): Edges of the graph.

    Returns:
        List[int]: The redundant edge that can be removed to make the graph a tree.

    Explanation:
        - This uses the "prune leaves" strategy by keeping only cycle nodes.
        - After removing leaf nodes iteratively, the remaining edges are part
          of at least one cycle. The last appearing such edge in edges is returned.
    """
    n = len(edges)
    indegree = [0] * (n + 1)
    adj = [[] for _ in range(n + 1)]

    # Build graph and indegree list
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)
        indegree[u] += 1
        indegree[v] += 1

    # Initialize queue with all leaf nodes (indegree 1)
    queue = deque()
    for i in range(1, n + 1):
        if indegree[i] == 1:
            queue.append(i)

    # Prune leaves iteratively
    while queue:
        node = queue.popleft()
        indegree[node] -= 1
        for neighbor in adj[node]:
            if indegree[neighbor] == 0:
                continue
            indegree[neighbor] -= 1
            if indegree[neighbor] == 1:
                queue.append(neighbor)

    # Find the last edge in edges that is part of a cycle
    for u, v in reversed(edges):
        if indegree[u] > 0 and indegree[v] > 0:
            return [u, v]
    return []


def main():
    """
    Example usage and demonstration of find_redundant_connection function.
    """
    # Example 1: One redundant connection (3, 1)
    edges1 = [[1, 2], [1, 3], [2, 3]]
    print(find_redundant_connection(edges1))  # Output: [2, 3]

    # Example 2: Redundant connection at the end
    edges2 = [[1, 2], [2, 3], [3, 4], [1, 4], [1, 5]]
    print(find_redundant_connection(edges2))  # Output: [1, 4]

if __name__ == "__main__":
    main()
