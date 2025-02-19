class Solution {
public:
    long long fun(int ind,vector<int>&nums,vector<long long>&dp){
        // cout<<"hi";
        int n=nums.size();
        if(ind>=n) return 0;
        if(ind==n-1) return 1;
        if(dp[ind]!=-1) return dp[ind];
        long long  jump=INT_MAX;
        for(int i=1;i<=nums[ind];i++){

            if(i+ind<n){
                long long temp=1+fun(i+ind,nums,dp);
                jump=min(jump,temp);
            }
        }
        return dp[ind]=jump;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<long long >dp(n,-1);
        return fun(0,nums,dp)-1;

    }
};