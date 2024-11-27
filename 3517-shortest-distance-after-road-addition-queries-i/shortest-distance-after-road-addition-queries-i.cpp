class Solution {
public:
    int fun(vector<vector<int>>&adj,int n){
        // int n=adj.size();
        queue<int>q;
        vector<int>dist(n,INT_MAX);
        q.push(0);
        dist[0]=0;
        while(!q.empty()){
            int node=q.front();
            // int distii=q.front().first;
            q.pop();
            if(node==n-1) return dist[node];
            for(auto it: adj[node]){
                if(1+dist[node]<dist[it]){
                    dist[it]=1+dist[node];
                    q.push(it);

                }
            }
        }
        return 0;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[i-1].push_back(i);
        }
        int m=queries.size();
        vector<int>ans(m);
        int pp=0;
        for(vector k: queries){
            int u=k[0];
            int v=k[1];
            adj[u].push_back(v);
            int val=fun(adj,n);
            ans[pp++]=val;
        }
        return ans;
    }
};