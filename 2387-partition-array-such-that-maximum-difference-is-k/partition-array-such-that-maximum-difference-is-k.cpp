class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int i = 0 , j = 0;

        int cnt = 1; // answer will at least 1

        while(j<nums.size()){
            if((nums[j] - nums[i]) <= k){
                j++;
            }
            else{
                // need for one more partition
                cnt++;
                i = j;
            }
        }
       
        return cnt;
    }
};