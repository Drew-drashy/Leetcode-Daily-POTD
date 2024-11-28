class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int x[4]={-1,0,1,0};
        int y[4]={0,1,0,-1};
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            for(int k=0;k<4;k++){
                int ii=i+x[k];
                int jj=j+y[k];
                if(ii>=0 && ii<n && jj>=0 && jj<m){
                    if(d+grid[ii][jj]<dist[ii][jj]){
                        dist[ii][jj]=d+grid[ii][jj];
                        pq.push({dist[ii][jj],{ii,jj}});
                    }
                }
            }
        }
        return dist[n-1][m-1];

    }
};