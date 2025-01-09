class Solution {
public:
    // Helper function for DFS
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited, vector<int>& redundantEdge) {
        visited[node] = 1;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                // Recur for the neighbor
                if (dfs(neighbor, node, adj, visited, redundantEdge)) {
                    return true;
                }
            } else if (neighbor != parent) {
                // Cycle detected
                redundantEdge = {node, neighbor};
                return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);  // Adjacency list
        vector<int> visited(n + 1, 0);  // Visited array
        vector<int> redundantEdge;      // To store the redundant edge

        // Build the adjacency list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

            // Reset visited array for each new edge
            fill(visited.begin(), visited.end(), 0);

            // Detect cycle using DFS
            if (dfs(u, -1, adj, visited, redundantEdge)) {
                return edge; // Return the redundant edge
            }
        }

        return {};
    }
};
