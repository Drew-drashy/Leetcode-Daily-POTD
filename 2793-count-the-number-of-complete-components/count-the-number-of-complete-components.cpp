class Solution {
public:
    void fun(int node,vector<vector<int>>&adj,int &e,int &v,vector<int>&vis){
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            v+=1;
            int curr=q.front();
            e+=adj[curr].size();
            q.pop();
            for(auto it: adj[curr]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int v=0;
                int e=0;
                fun(i,adj,e,v,vis);
                if(v*(v-1)==e) cnt++;
            }
        }
        return cnt;
    }
};