// class Solution {
// public:
//     long long  fun(int c,int n, int limit,vector<vector<long  long>>&dp){
//         if(c==0 && n==0) return 1;
//         if(c<=0)  return  0;
//         // if(n<=0)  return  0;
//         if(dp[n][c]!=-1)  return dp[n][c];
//         long long ans=0;
//         for(int i=0;i<=limit;i++){
//             if(i<=n){
//                 ans+=fun(c-1,n-i,limit,dp);
//             }
//         }
//     return dp[n][c]=ans;
//     }
//     long long distributeCandies(int n, int limit) {
//         vector<vector<long long>>dp(n+1,vector<long long>(4,0));
//         dp[0][0]=1;

//         return fun(3,n,limit,dp);
//     }
// };/
class Solution {
public:
    long long distributeCandies(int n, int limit) {
      
        vector<vector<long long>> dp(4, vector<long long>(n + 1, 0));
        dp[0][0] = 1;

        for (int c = 1; c <= 3; ++c) {
            vector<long long> prefix(n + 2, 0);
            for (int x = 0; x <= n; ++x) {
                prefix[x + 1] = prefix[x] + dp[c - 1][x];
            }
            for (int x = 0; x <= n; ++x) {
                int l = max(0, x - limit);
                int r = x;
                dp[c][x] = prefix[r + 1] - prefix[l];
            }
        }
        return dp[3][n];
    }
};
