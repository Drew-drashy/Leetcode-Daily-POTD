class Solution {
public:
    int MOD=1e9+7;
    int fun(int node,vector<vector<int>>&adj,vector<int>vis){
        queue<int>q;
        q.push(node);
        vis[node]=1;
        int dep=0;
        int maxi=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            dep++;
            //  cout<<"bi\n";
            maxi=max(maxi,dep);
            for(auto it: adj[node]){
                // cout<<it<<"\n";
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return   maxi;
    }
    int power(int base, int exp,  int mod){
         long long result = 1;
        long long b = base;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * b) % mod;
            b = (b * b) % mod;
            exp /= 2;
        }
        return result;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>graph(n+2);
        // cout<<"i\n";
        for(auto it: edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int>visited(n+2,0);
        int maxi=0;
        
        queue<pair<int,int>>pq;
        pq.push({0,1});
        visited[1]=1;
        while(!pq.empty()){
            int n=pq.size();
            while(n--){
                auto it=pq.front();
                pq.pop();
                int node=it.second;
                int dep=it.first;
                maxi=max(maxi,dep);
                for(auto op: graph[node]){
                    if(!visited[op]){
                        pq.push({dep+1,op});
                        visited[op]=1;
                    }
                }
            }
        }
        cout<<maxi<<"\n";
        return  power(2,maxi-1,MOD);
    }
};