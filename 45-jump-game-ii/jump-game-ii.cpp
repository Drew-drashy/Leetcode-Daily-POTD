class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();

        int l=0;
        int r=0;
        int jumps=0;

        while(r < n-1){

            int fastest=0;

            for(int i=l;i<=r;i++){
                fastest=max(i+nums[i],fastest);
            }

            l=r+1;
            r=fastest;
            jumps+=1;
        }
        return jumps;
    }
};