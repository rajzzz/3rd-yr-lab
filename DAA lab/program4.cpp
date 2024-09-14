#include <bits/stdc++.h>
using namespace std;

// DSU data structure
// path compression + rank by union
class DSU {
    int* parent;
    int* rank;

public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find function
    int find(int i) {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    // Union function
    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            } else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            } else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }

    ~DSU() {
        delete[] parent;
        delete[] rank;
    }
};

class Graph {
    vector<vector<int>> edgelist;
    int V;

public:
    Graph(int V) { this->V = V; }

    // Function to add edge in a graph
    void addEdge(int x, int y, int w) {
        edgelist.push_back({ w, x, y });
    }

    int kruskals_mst() {
        // Sort all edges
        sort(edgelist.begin(), edgelist.end());

        // Initialize the DSU
        DSU s(V);
        int ans = 0;
        for (auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // Take this edge in MST if it does not form a cycle
            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }

    int getNumberOfEdges() {
        return edgelist.size();
    }
};

void generateRandomEdges(Graph& g, int V) {
    int maxEdges = V * (V - 1) / 2;
    int E = rand() % maxEdges + 1; // Random number of edges between 1 and maxEdges

    set<pair<int, int>> existingEdges;

    // Ensure the graph is connected by creating a spanning tree first
    for (int i = 1; i < V; ++i) {
        int src = rand() % i;
        int dest = i;
        int weight = rand() % 100 + 1; // Random weight between 1 and 100
        g.addEdge(src, dest, weight);
        existingEdges.insert({min(src, dest), max(src, dest)});
    }

    // Add remaining random edges
    for (int i = V - 1; i < E; ++i) {
        int src, dest;
        do {
            src = rand() % V;
            dest = rand() % V;
        } while (src == dest || existingEdges.count({min(src, dest), max(src, dest)}));

        int weight = rand() % 100 + 1; // Random weight between 1 and 100
        g.addEdge(src, dest, weight);
        existingEdges.insert({min(src, dest), max(src, dest)});
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    int sizes[] = {100, 500, 1000, 1500, 2000}; // Number of vertices

    for (int V : sizes) {
        Graph g(V);
        generateRandomEdges(g, V);

        clock_t start = clock();
        int mst_cost = g.kruskals_mst();
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000; // in microseconds
        int num_edges = g.getNumberOfEdges();
        printf("Time taken for Kruskal's algorithm with %d vertices and %d edges: %.2f microseconds\n", V, num_edges, time_taken);
        printf("Cost of the Minimum Spanning Tree: %d\n", mst_cost);
        cout << "=============================================\n";
    }

    return 0;
}