class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        dist[0][0]=0;
        int x[4]={-1,0,1,0};
        int y[4]={0,1,0,-1};
        while(!q.empty()){
            int dis=q.top().first;
            int i=q.top().second.first;
            int j=q.top().second.second;
            
            q.pop();
            for(int k=0;k<=3;k++){
                int ii=x[k]+i;
                int jj=y[k]+j;

                if(ii>=0 && ii<n && jj>=0 && jj<m){
                    if(1+max(grid[ii][jj],dis)<dist[ii][jj]){
                        dist[ii][jj]=1+max(grid[ii][jj],dis);
                        q.push({dist[ii][jj],{ii,jj}});
                    }
                }
            }
        }
        return dist[n-1][m-1];

    }
};