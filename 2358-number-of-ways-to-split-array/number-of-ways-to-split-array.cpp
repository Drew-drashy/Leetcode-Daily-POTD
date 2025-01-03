class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        vector<long long>pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=1LL*(pre[i-1]+nums[i]);
        }
        long long val=pre[n-1];
        for(int i=0;i<n-1;i++){
            if(pre[i]>=val-pre[i]) ans++;
        }
        return ans;
    }
};