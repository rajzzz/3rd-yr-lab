from collections import defaultdict, deque

class Graph:
    def __init__(self):
        # Create an adjacency list to store the graph
        self.graph = defaultdict(list)
    
    def add_edge(self, vertex1, vertex2):
        # Add edges to the undirected graph
        self.graph[vertex1].append(vertex2)
        self.graph[vertex2].append(vertex1)
    
    def bfs(self, start_vertex):
        # Set to keep track of visited vertices
        visited = set()
        
        # Create a queue for BFS
        queue = deque([start_vertex])
        visited.add(start_vertex)
        
        while queue:
            # Dequeue a vertex from queue and print it
            current_vertex = queue.popleft()
            print(current_vertex, end=' ')
            
            # Get all adjacent vertices
            # If an adjacent has not been visited, then mark it visited
            # and enqueue it
            for neighbor in self.graph[current_vertex]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)


# Create a graph
g = Graph()

# Get number of vertices
num_vertices = int(input("Enter number of vertices: "))

# Get number of edges
num_edges = int(input("Enter number of edges: "))

# Get edges
print("\nEnter edges (vertex1 vertex2):")
for i in range(num_edges):
    v1, v2 = map(int, input(f"Edge {i+1}: ").split())
    g.add_edge(v1, v2)

# Get starting vertex
start = int(input("\nEnter starting vertex for BFS: "))

# Perform BFS and print result
print("\nBreadth First Traversal (starting from vertex", start, "):")
g.bfs(start)
