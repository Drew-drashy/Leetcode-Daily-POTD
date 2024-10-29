class Solution {
public:
    int fun(int i,int j,int prev,vector<vector<int>>&grid,vector<vector<int>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(prev>=grid[i][j]) return 0;
        prev=grid[i][j];
        int a=fun(i-1,j+1,prev,grid,dp);
        int b=fun(i,j+1,prev,grid,dp);
        int c=fun(i+1,j+1,prev,grid,dp);
        return dp[i][j]=1+max({a,b,c});

    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            ans=max(ans,fun(i,0,-1,grid,dp));
        }
        return ans-1;
    }
};