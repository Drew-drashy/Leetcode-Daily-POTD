class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        int cnt=0;
        vector<vector<int>>graph(n);
        queue<int>q;
        vector<int>indegree(n,0);
        for(auto it: pre){
            graph[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        for(int i=0;i<n;i++){
            if(!indegree[i])
            q.push(i);
        }
        int visited=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            visited++;
            for(auto it: graph[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(visited==n)  return true;
        else return false;


    }
};