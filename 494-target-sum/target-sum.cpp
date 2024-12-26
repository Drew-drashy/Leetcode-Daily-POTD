class Solution {
public:
    int fun(int ind ,int target,vector<int>&nums,vector<vector<int>>&dp){
        int n=nums.size();
        // if(target==0) return 1;
        if(ind>=n){
            if(target==0) return 1;
            else return 0;
        }
        if(dp[ind][target+1000]!=-1) return dp[ind][target+1000];
        int him=fun(ind+1,target-nums[ind],nums,dp);
        int cream=fun(ind+1,target+nums[ind],nums,dp);
        return dp[ind][target+1000]=him+cream;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(3001,-1));
        return fun(0,target,nums,dp);

    }
};