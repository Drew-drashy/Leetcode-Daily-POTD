class Solution {
public:

    int fun(int i, int j,string &text1,string&text2,vector<vector<int>>&dp){
        if( i<0 || j<0 ) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        // int o=0;
        if(text1[i]==text2[j]){
            return dp[i][j]=1+fun(i-1,j-1,text1,text2,dp);
        }
        return dp[i][j]=max(fun(i-1,j,text1,text2,dp),fun(i,j-1,text1,text2,dp));

        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(n-1,m-1,text1,text2,dp);
    }
};