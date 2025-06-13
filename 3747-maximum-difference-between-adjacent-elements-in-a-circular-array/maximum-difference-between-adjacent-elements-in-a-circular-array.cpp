class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int cnt=abs(nums[i]-nums[(i+1)%n]);
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};