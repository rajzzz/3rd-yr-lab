#include <iostream>
#include <vector>
#include <limits.h>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;
using namespace chrono;

struct Edge
{
    int src, dest, weight;
};

class BellmanFord
{
    int vertices;
    vector<Edge> edges;

public:
    BellmanFord(int vertices)
    {
        this->vertices = vertices;
    }

    void addEdge(int src, int dest, int weight)
    {
        edges.push_back({src, dest, weight});
    }

    vector<int> bellmanFord(int source)
    {
        vector<int> distance(vertices, INT_MAX);
        distance[source] = 0;

        // Relax all edges V-1 times
        for (int i = 1; i < vertices; ++i)
        {
            for (const auto &edge : edges)
            {
                int u = edge.src;
                int v = edge.dest;
                int weight = edge.weight;

                if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                }
            }
        }

        // Check for negative weight cycles
        for (const auto &edge : edges)
        {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
            {
                cout << "Graph contains negative weight cycle!" << endl;
                return vector<int>();
            }
        }

        return distance;
    }
};

// Function to generate random graph
BellmanFord generateRandomGraph(int V, int E)
{
    BellmanFord graph(V);

    for (int i = 0; i < E; i++)
    {
        int src = rand() % V;
        int dest = rand() % V;
        int weight = rand() % 100 - 25; // Weights between -25 and 74
        graph.addEdge(src, dest, weight);
    }
    return graph;
}

int main()
{
    srand(time(0)); // Initialize random seed

    // Test cases with different graph sizes
    vector<pair<int, int>> test_cases = {
        {100, 300},   // V=100, E=300
        {500, 1500},  // V=500, E=1500
        {1000, 3000}, // V=1000, E=3000
        {1500, 4500}, // V=1500, E=4500
        {2000, 6000}  // V=2000, E=6000
    };

    for (const auto &test : test_cases)
    {
        int V = test.first;
        int E = test.second;

        cout << "Number of Vertices: " << V << endl;
        cout << "Number of Edges: " << E << endl;

        // Generate random graph
        BellmanFord graph = generateRandomGraph(V, E);

        // Choose random source vertex
        int source = rand() % V;

        // Measure execution time
        auto start = high_resolution_clock::now();
        vector<int> distances = graph.bellmanFord(source);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start).count();
        cout << "Time Taken: " << duration << " microseconds" << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}