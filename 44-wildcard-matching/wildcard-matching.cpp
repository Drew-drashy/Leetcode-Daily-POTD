class Solution {
public:
    bool fun(int i,int j,string &s,string &p,vector<vector<int>>&dp){
        if(i<0 && j>=0){
            while(j>=0){
                if(p[j]!='*'){
                    return false;
                }
                j--;
            }
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j<0) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool tu=false;
        if(s[i]==p[j] || p[j]=='?'){
            tu=tu||fun(i-1,j-1,s,p,dp);
        }
        else if(p[j]=='*'){
            tu=tu||fun(i-1,j,s,p,dp) || fun(i-1,j-1,s,p,dp) || fun(i,j-1,s,p,dp);
        }
        return dp[i][j]=tu;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        if(s==p) return true;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(n-1,m-1,s,p,dp);
    }   
};