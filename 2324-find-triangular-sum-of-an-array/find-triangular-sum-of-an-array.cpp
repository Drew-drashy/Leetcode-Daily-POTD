class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        
        int o=nums.size();
        for(int size=o;size>1;size--){
            for(int i=0;i<size-1;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
            
        }
        return nums[0];
        

    }
};