from collections import deque

def bfs(tree, start):
    visited = set()
    queue = deque([start])
    traversal_order = []

    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.add(node)
            traversal_order.append(node)

            for neighbor in tree[node]:
                if neighbor not in visited:
                    queue.append(neighbor)

    return traversal_order

graph={
    'A': ['B', 'C'],
    'B': ['A','D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'G'],
    'F': ['C'],
    'G': ['E']
}

result = bfs(graph, 'A')
print(f"BFS Traversal Order: {result}")