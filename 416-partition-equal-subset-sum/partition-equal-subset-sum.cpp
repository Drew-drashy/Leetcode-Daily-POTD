class Solution {
public:
    bool fun(int i,int k,vector<int>&arr,vector<vector<int>>&dp){
        if(i==0){
            return arr[i]==k;
        }
        if(k==0) return true;
        if(dp[i][k]!=-1) return dp[i][k];
        bool ntake,take=false;
        ntake=fun(i-1,k,arr,dp);
        if(arr[i]<=k){
            take=fun(i-1,k-arr[i],arr,dp);
        }
        return dp[i][k]=ntake||take;
    }
    bool canPartition(vector<int>& arr) {
                int tot=0;
        int N=arr.size();
        for(int i=0;i<N;i++){
                tot+=arr[i];
        }
        if(tot%2!=0) return 0;
        // else{
            int k=tot/2;
            vector<vector<int>>dp(N,vector<int>(k+1,-1));
            
            // if(){
            //     return 1;
            // }
            // else{
            //     return 0;
            // }
        // }
       return fun(N-1,k,arr,dp);
        
    }
};