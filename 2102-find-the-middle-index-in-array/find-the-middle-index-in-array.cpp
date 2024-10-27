class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int left=0;
        int res=0;
        int n=nums.size();
        if(n==1) return 0;
        for(int i: nums) res+=i;
        for(int i=0;i<n;i++){
            int right=res-nums[i]-left;
            if(left==right) return i;
            
            left+=nums[i];
        }
        return -1;
    }
};