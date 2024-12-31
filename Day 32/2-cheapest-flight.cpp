// Solve the "cheapest flights within k stops" problem using modified BFS.

#include <iostream>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

#define MAX 1000    // Maximum number of cities

class CheapestFlights {
    private:
        int adj_matrix[MAX][MAX];  // Adjacency matrix to store flight costs
        int num_cities;            // Number of cities

    public:
        CheapestFlights(int cities) {
            num_cities = cities;
            for (int i = 0; i < num_cities; i++) {
                for (int j = 0; j < num_cities; j++) {
                    adj_matrix[i][j] = -1;  // Initialize with no direct connection
                }
            }
        }

        void add_flight(int src, int dest, int cost) {
            adj_matrix[src][dest] = cost;
        }

        int find_cheapest_flight(int src, int dest, int k) {
            queue<pair<int, pair<int, int>>> bfs_queue;  // {stops, {current_city, cost}}
            bfs_queue.push({0, {src, 0}});
            int min_cost[MAX];

            // Initialize minimum cost to reach each city as infinity
            for (int i = 0; i < num_cities; i++) {
                min_cost[i] = INT_MAX;
            }

            min_cost[src] = 0;

            while (!bfs_queue.empty()) {
                auto front = bfs_queue.front();
                bfs_queue.pop();

                int stops = front.first;
                int current_city = front.second.first;
                int current_cost = front.second.second;

                // If the number of stops exceeds k, skip further processing
                if (stops > k) {
                    continue;
                }

                // Explore neighbors
                for (int neighbor = 0; neighbor < num_cities; neighbor++) {
                    if (adj_matrix[current_city][neighbor] != -1) {
                        int new_cost = current_cost + adj_matrix[current_city][neighbor];

                        // Only proceed if the new cost is lower
                        if (new_cost < min_cost[neighbor]) {
                            min_cost[neighbor] = new_cost;
                            bfs_queue.push({stops + 1, {neighbor, new_cost}});
                        }
                    }
                }
            }

            return min_cost[dest] == INT_MAX ? -1 : min_cost[dest];
        }
};

int main() {
    int num_cities = 4;
    CheapestFlights flights(num_cities);
    flights.add_flight(0, 1, 100);
    flights.add_flight(1, 2, 100);
    flights.add_flight(0, 2, 500);
    flights.add_flight(2, 3, 100);
    int src = 0, dest = 3, k = 2;
    cout << "Cheapest price from " << src << " to " << dest << " within " << k << " stops: "
         << flights.find_cheapest_flight(src, dest, k) << endl;

    return 0;
}
