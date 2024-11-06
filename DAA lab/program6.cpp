#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;
using namespace std::chrono;

typedef pair<int, int> pii;

// Function to generate random graph
vector<vector<pii>> generateRandomGraph(int V, int E) {
    vector<vector<pii>> graph(V);
    
    for(int i = 0; i < E; i++) {
        int u = rand() % V;
        int v = rand() % V;
        int weight = rand() % 100 + 1; // Random weight between 1 and 100
        
        // Add edge in both directions
        graph[u].push_back({weight, v});
        graph[v].push_back({weight, u});
    }
    return graph;
}

// Dijkstra's algorithm implementation
vector<int> dijkstra(const vector<vector<pii>>& graph, int source) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[source] = 0;
    pq.push({0, source});
    
    while(!pq.empty()) {
        int u = pq.top().second;
        int uDist = pq.top().first;
        pq.pop();
        
        if(uDist > dist[u]) continue;
        
        for(const auto& edge : graph[u]) {
            int weight = edge.first;
            int v = edge.second;
            
            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    srand(time(0));  // Initialize random seed
    
    // Test cases with different graph sizes
    vector<pair<int,int>> test_cases = {
        {100, 500},    // V=100, E=500
        {500, 2500},   // V=500, E=2500
        {1000, 5000},  // V=1000, E=5000
        {1500, 7500},  // V=1500, E=7500
        {2000, 10000}  // V=2000, E=10000
    };
    
    for(const auto& test : test_cases) {
        int V = test.first;
        int E = test.second;
        
        cout << "Number of Vertices: " << V << endl;
        cout << "Number of Edges: " << E << endl;
        
        // Generate random graph
        vector<vector<pii>> graph = generateRandomGraph(V, E);
        
        // Choose random source vertex
        int source = rand() % V;
        
        // Measure execution time
        auto start = high_resolution_clock::now();
        vector<int> distances = dijkstra(graph, source);
        auto end = high_resolution_clock::now();
        
        auto duration = duration_cast<microseconds>(end - start).count();
        cout << "Time Taken: " << duration << " microseconds" << endl;
        cout << "----------------------------------------" << endl;
    }
    
    return 0;
}