class Solution {
public:
    int trapRainWater(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // Min-heap
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // Add boundary cells to the priority queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    pq.push({arr[i][j], {i, j}});
                    vis[i][j] = 1;
                }
            }
        }
        
        int cnt = 0;
        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, 1, 0, -1};

        // Process the cells
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int h = it.first;
            int i = it.second.first;
            int j = it.second.second;
            
            for (int k = 0; k < 4; k++) {
                int ii = i + x[k];
                int jj = j + y[k];
                
                if (ii >= 0 && ii < n && jj >= 0 && jj < m && !vis[ii][jj]) {
                    vis[ii][jj] = 1;
                    cnt += max(h - arr[ii][jj], 0); // Add water trapped
                    int newHeight = max(h, arr[ii][jj]);
                    pq.push({newHeight, {ii, jj}});
                }
            }
        }
        return cnt;
    }
};
