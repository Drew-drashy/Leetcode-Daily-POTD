class Solution {
public:
    int fun(int val){
        int cnt=0;
        while(val>0){
            cnt+=val%10;
            val/=10;
        }
        return cnt;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i==fun(nums[i])){
                return i;
            }
        }
        return -1;
    }
};