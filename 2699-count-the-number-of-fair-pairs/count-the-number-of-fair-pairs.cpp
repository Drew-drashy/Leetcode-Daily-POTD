class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
           int l=lower-nums[i];
           int u=upper-nums[i];
           int a=upper_bound(nums.begin()+i+1,nums.end(),u)-nums.begin();
           int b=lower_bound(nums.begin()+i+1,nums.end(),l)-nums.begin();
           ans+=a-b;
        }
        return ans;
    }
};