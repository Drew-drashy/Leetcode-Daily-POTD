class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        // int sum=0;
        int currsum=nums[0];

        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                currsum+=nums[i];
            }
            else{

                
                maxi=max(maxi,currsum);
                currsum=nums[i];
            }
        }
        return max(maxi,currsum);
    }
};