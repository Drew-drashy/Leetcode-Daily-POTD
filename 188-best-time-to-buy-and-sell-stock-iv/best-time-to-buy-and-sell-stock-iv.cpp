class Solution {
public:
    int fun(int ind,int k,int ch,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(ind>=prices.size()) return 0;
        if(k<=0) return 0;
        if(dp[ind][k][ch]!=-1) return dp[ind][k][ch];
        int buy=LLONG_MAX;
        
        if(ch==0){
            buy=max(-prices[ind]+fun(ind+1,k,1,prices,dp),fun(ind+1,k,0,prices,dp));
        }
        else{
            buy=max(prices[ind]+fun(ind+1,k-1,0,prices,dp),fun(ind+1,k,1,prices,dp));
        }
        return dp[ind][k][ch]=buy;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
            vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
            return fun(0,k,0,prices,dp);
    }
};