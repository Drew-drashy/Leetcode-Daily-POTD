class Solution {
public:
    int fun(int i,int j,vector<vector<int>>matrix,vector<vector<int>>&dp){
        int n=matrix.size();
        int m=matrix[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(matrix[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int d=1+fun(i+1,j+1,matrix,dp);
        int r=1+fun(i,j+1,matrix,dp);
        int l=1+fun(i+1,j,matrix,dp);
        return dp[i][j]=min(d,min(r,l));

    }
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // int ans=0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(matrix[i][j]!=0){
        //             ans+=fun(i,j,matrix,dp);
        //         }
        //     }
        // }
        // return ans;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    dp[i][j]=matrix[i][j];
                }
                else if(matrix[i][j]){
                    dp[i][j]=1+min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j] });
                }
                // ans+=dp[i][j];
            }
          
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};