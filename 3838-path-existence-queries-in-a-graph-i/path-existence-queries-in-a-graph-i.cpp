class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int> graph;
        graph.push_back(0);
        for (int i = 1; i < n; i++) {
                if (abs(nums[i] - nums[i-1]) <= maxDiff) {
                    graph.push_back(graph[i-1]);
                }
                else{
                    graph.push_back(graph[i-1]+1);
                }
          
        }
        
        
        vector<bool> answer;
        for (auto& query : queries) {
            int start = graph[query[0]], end = graph[query[1]];
            answer.push_back(start==end);
        }
        
        return answer;
    }
    private:
    bool bfs(vector<vector<int>>& graph, int start, int end, int n) {
        if (start == end) return true;
        
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    if (neighbor == end) return true;
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        return false;
    }
};