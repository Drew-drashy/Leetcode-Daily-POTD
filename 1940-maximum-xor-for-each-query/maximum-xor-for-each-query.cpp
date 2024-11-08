class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>ans(nums.size());
        int mask=(1<<maximumBit)-1;
        int x=0;
        for(int i: nums) x^=i;
        int n=nums.size();
        int ind=0;
        for(int i=n-1;i>=0;i--){
            int rev=x^mask;
            ans[ind++]=rev;
            x^=nums[i];
        }
        return ans;
    }
}; 