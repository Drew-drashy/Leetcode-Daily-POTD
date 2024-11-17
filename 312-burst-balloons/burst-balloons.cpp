class Solution {
public:
    // int fun(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     long long  res=LLONG_MIN;
    //     for(int k=i;k<=j;++k){
    //         long long ans=nums[i-1]*nums[k]*nums[j+1]+fun(i,k-1,nums,dp)+fun(k+1,j,nums,dp);
    //         res=max(res,ans);
    //     }
        
    //     return dp[i][j]=(int)res;
        
    // }
    int fun(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long ans=LLONG_MIN;
        for(int k=i;k<=j;k++){
            long long io=nums[i-1]*nums[k]*nums[j+1] + fun(i,k-1,nums,dp)+fun(k+1,j,nums,dp);
            ans=max(ans,io);
            
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        // int n=nums.size();
        // nums.push_back(1);
        // nums.insert(nums.begin(),1);
        // vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        // return fun(1,n,nums,dp);
        // for bursting the ballon where is the last and one'

        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return fun(1,n,nums,dp);
    }
};