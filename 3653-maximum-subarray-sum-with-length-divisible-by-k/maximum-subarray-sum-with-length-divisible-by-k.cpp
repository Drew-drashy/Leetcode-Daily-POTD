class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        
        long long ans = -1e15;
        long long sum = 0;
        vector<long long>pre(nums.size(),0);
        pre[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            pre[i] = 1LL*nums[i]+1LL*pre[i-1];
        }
        
        for(int j = 0;j<k;j++){
            for(int i = j+k-1;i<nums.size();i+=k){
                sum+=(1LL*pre[i]-(i>=k?1LL*pre[i-k]:0LL));
                ans = max(ans,sum);
                if(sum<0)sum = 0;  
            }
            sum = 0;
        }
        
        return ans;
    }
};