class Solution {
public:
    long long  solve(int i,int j,vector<int>&robot,vector<int>&positions,vector<vector<long long>>&dp){
        if(i>=robot.size()) return 0;
        if(j>=positions.size()) return 1e12;
        if(dp[i][j]!=-1) return dp[i][j];
        long long  take=abs(robot[i]-positions[j])+solve(i+1,j+1,robot,positions,dp);
        long long ntake=solve(i,j+1,robot,positions,dp);
        return dp[i][j]=min(take,ntake);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n=factory.size();
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int>positions;
        for(int i=0;i<n;i++){
            for(int j=0;j<factory[i][1];j++){
                positions.push_back(factory[i][0]);
            }
        }
        n=positions.size();
        int m=robot.size();
        vector<vector<long long>>dp(m,vector<long long >(n,-1));
        return solve(0,0,robot,positions,dp);
    }
};