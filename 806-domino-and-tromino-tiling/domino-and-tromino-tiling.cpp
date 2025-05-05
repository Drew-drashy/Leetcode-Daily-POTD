class Solution {
public:
    int mod=1e9+7;
    int dp[10001];
    int fun(int ind){
        if(ind==1) return 1;
        else if(ind==2) return 2;
        else if(ind==3) return 5;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=((2*dp[ind-1])%mod+(dp[ind-3])%mod)%mod;
    }
    int numTilings(int n) {
        // return fun(n);
        if(n<=0) return 0;
        if(n==1 || n==2) return n;
        vector<int>dp(1001,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(int i=4;i<=n;i++){
            dp[i]=(2*dp[i-1]%mod + dp[i-3]%mod)%mod;
        }
        return dp[n];
    }
};