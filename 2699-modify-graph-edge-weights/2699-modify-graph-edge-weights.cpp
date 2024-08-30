class Solution {
public:
    const int INF = 2e9; // Constant representing infinity for unbounded edges
    typedef pair<int,int> pi; // Type alias for pairs of integers (cost, node)

    // Dijkstra's algorithm to find the shortest path from source to destination
    int diajstra(int n, int source, int destination, vector<pi> adj[]) {
        vector<int> distance(n, INT_MAX); // Initialize distances to all nodes as infinity
        distance[source] = 0; // Distance from source to itself is 0
        priority_queue<pi, vector<pi>, greater<pi>> pq; // Min-heap priority queue for nodes

        pq.push({0, source}); // Push the source node into the queue

        while (!pq.empty()) {
            auto [cost, node] = pq.top(); pq.pop(); // Get the node with the smallest distance

            // If we've reached the destination, we can stop the search
            if (node == destination) break;

            // Explore all adjacent nodes of the current node
            for (auto [ccost, cnode] : adj[node]) {
                // If a shorter path to the adjacent node is found
                if (cost + ccost < distance[cnode]) {
                    distance[cnode] = cost + ccost; // Update the distance
                    pq.push({distance[cnode], cnode}); // Add the updated distance to the queue
                }
            }
        }
        return distance[destination]; // Return the shortest distance to the destination
    }

    // Function to modify graph edges to achieve a specific target path length
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<pi> adj[n]; // Adjacency list representation of the graph

        // Construct the adjacency list, ignoring edges with a cost of -1
        for (auto &e : edges) {
            if (e[2] == -1) continue; // Skip edges with unknown cost
            adj[e[0]].push_back({e[2], e[1]}); // Add edge to the adjacency list
            adj[e[1]].push_back({e[2], e[0]}); // Undirected graph: add both directions
        }

        // Get the shortest distance from source to destination using Dijkstra's algorithm
        int sortedDistance = diajstra(n, source, destination, adj);
        
        // If the shortest distance is less than the target, return an empty vector
        if (sortedDistance < target) return {};

        bool isEqual = sortedDistance == target; // Check if current distance equals target

        // Modify edges with cost of -1 to find a valid configuration
        for (auto &e : edges) {
            if (e[2] != -1) continue; // Skip edges with a known cost
            
            // Set a temporary cost for the edge
            e[2] = isEqual ? INF : 1; // If distances equal target, set to infinity; otherwise, set to 1
            adj[e[0]].push_back({e[2], e[1]}); // Add modified edge to adjacency list
            adj[e[1]].push_back({e[2], e[0]}); // Add reverse edge

            // If the shortest path is not equal to the target
            if (!isEqual) {
                // Calculate the new shortest path with the modified edge
                int newSortedPath = diajstra(n, source, destination, adj);
                // If the new path is less than or equal to the target, adjust the edge cost
                if (newSortedPath <= target) {
                    isEqual = true; // Mark that we have found a valid path
                    e[2] += target - newSortedPath; // Adjust the edge cost to reach the target
                }
            }
        }  
        // If a valid configuration is found, return the modified edges
        if (isEqual) return edges;
        return {}; // If no valid configuration is found, return an empty vector
    }
};