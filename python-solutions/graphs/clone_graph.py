from typing import Optional, Dict, List

class Node:
    """
    A Node in an undirected graph.
    
    Attributes:
        val (int): The value of the node.
        neighbors (List['Node']): List of references to neighboring nodes.
    """
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

def dfs(node: Optional['Node'], old_to_new: Dict['Node', 'Node']) -> Optional['Node']:
    """
    Performs DFS to create a deep copy of the graph starting from the given node.

    Args:
        node (Optional['Node']): The current node to clone.
        old_to_new (Dict['Node', 'Node']): Dictionary mapping original nodes to their clones.

    Returns:
        Optional['Node']: The cloned node.
    """
    if node in old_to_new:
        # Node was already copied, so return the copy (prevents cycles & repeats).
        return old_to_new[node]

    # Create a copy for the current node.
    copy = Node(node.val)
    # Map the original node to its copy.
    old_to_new[node] = copy

    # Iterate over all neighbors, recursively clone them, and add to the copy's neighbors.
    for nei in node.neighbors:
        copy.neighbors.append(dfs(nei, old_to_new))
    return copy

def cloneGraph(node: Optional['Node']) -> Optional['Node']:
    """
    Returns a deep copy of the input undirected graph.

    Args:
        node (Optional['Node']): Reference to a node in the original graph.

    Returns:
        Optional['Node']: Reference to the node in the deep-copied graph.
    """
    if not node:
        # Null graph case.
        return None
    old_to_new = dict()
    return dfs(node, old_to_new)

def main():
    """
    Constructs a simple test undirected graph and demonstrates the cloning operation.
    Prints attributes of the original and cloned graphs to verify correctness.
    """
    # Build a 2-node undirected graph, 1--2 (both are each other's neighbors)
    node1 = Node(1)
    node2 = Node(2)
    node1.neighbors.append(node2)
    node2.neighbors.append(node1)

    # Clone the graph starting from node1
    clone = cloneGraph(node1)

    # Simple check: Verify that the nodes have correct values, neighbors, and are deep copied
    print("Original node1 value:", node1.val)
    print("Clone node1 value:", clone.val)
    print("Original node1 neighbors:", [n.val for n in node1.neighbors])
    print("Clone node1 neighbors:", [n.val for n in clone.neighbors])
    print("Original node1 is clone node1:", node1 is clone)
    print("Original neighbor is clone neighbor:", node1.neighbors[0] is clone.neighbors[0])

if __name__ == "__main__":
    main()
