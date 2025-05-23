class Solution {
public:
    int fun(int ind, int n,vector<int>&nums,vector<int>&dp){
        if(ind>n){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int take=nums[ind]+fun(ind+2,n,nums,dp);
        int ntake=fun(ind+1,n,nums,dp);

        return dp[ind]=max(take,ntake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n,-1);
        vector<int>sp(n,-1);
        return max(fun(0,n-2,nums,dp), fun(1,n-1,nums,sp));
    }
};