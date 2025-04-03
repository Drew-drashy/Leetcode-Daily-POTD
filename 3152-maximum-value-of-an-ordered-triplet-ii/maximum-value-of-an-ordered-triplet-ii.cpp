class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi_num=0;
        long long maxdiff=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,(long long)maxdiff*nums[i]);
            maxi_num=max(maxi_num,(long long)nums[i]);
            maxdiff=max(maxdiff,(long long)maxi_num-nums[i]);
        }
        return ans;
    }
};