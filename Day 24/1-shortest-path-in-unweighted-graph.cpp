// Solve the "find the shortest path in an unweighted graph" problem using BFS.

#include <iostream>
#include <queue>
using namespace std;

#define MAX 10          // Maximum number of vertices in the graph

// Graph represented using adjacency list
struct Node {
    int vertex;
    Node* next;
};

// Graph class with BFS-based shortest path functionality
class Graph {
    private:
        Node* adjList[MAX]; // Adjacency list for the graph

    public:
        // Constructor to initialize the graph
        Graph() {
            for (int i = 0; i < MAX; i++) {
                adjList[i] = nullptr;
            }
        }

        // Function to add an edge to the graph (undirected)
        void add_edge(int src, int dest) {
            // Add edge from src to dest
            Node* newNode = new Node;
            newNode->vertex = dest;
            newNode->next = adjList[src];
            adjList[src] = newNode;

            // Add edge from dest to src (since it's an undirected graph)
            newNode = new Node;
            newNode->vertex = src;
            newNode->next = adjList[dest];
            adjList[dest] = newNode;
        }

        // BFS function to find the shortest path from source to destination
        void shortest_path(int source, int destination) {
            bool visited[MAX] = {false}; // Visited array
            int predecessor[MAX];        // Array to store predecessors
            int distance[MAX];           // Array to store distances from the source

            // Initialize distance and predecessor arrays
            for (int i = 0; i < MAX; i++) {
                predecessor[i] = -1;
                distance[i] = -1;
            }

            // BFS queue
            queue<int> q;
            visited[source] = true;
            distance[source] = 0;
            q.push(source);

            // Perform BFS
            while (!q.empty()) {
                int current = q.front();
                q.pop();

                // Explore all neighbors of the current vertex
                Node* temp = adjList[current];
                while (temp != nullptr) {
                    if (!visited[temp->vertex]) {
                        visited[temp->vertex] = true;
                        distance[temp->vertex] = distance[current] + 1;
                        predecessor[temp->vertex] = current;
                        q.push(temp->vertex);

                        // Stop BFS when the destination is reached
                        if (temp->vertex == destination) {
                            break;
                        }
                    }
                    temp = temp->next;
                }
            }

            // If destination is not reachable
            if (!visited[destination]) {
                cout << "No path exists between " << source << " and " << destination << endl;
                return;
            }

            // Reconstruct the shortest path using the predecessor array
            int crawl = destination;
            cout << "Shortest path length is: " << distance[destination] << endl;
            cout << "Path: ";
            while (crawl != -1) {
                cout << crawl << " ";
                crawl = predecessor[crawl];
            }
            cout << endl;
        }
};

int main() {
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 5);
    int source = 0, destination = 5;
    g.shortest_path(source, destination);
    return 0;
}
