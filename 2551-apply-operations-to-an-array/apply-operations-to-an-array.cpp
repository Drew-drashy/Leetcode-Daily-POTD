class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=2*nums[i];
                nums[i+1]=0;
            }
        }
        vector<int>res;
        int k=0;
        for(int i: nums){
            if(i!=0) res.push_back(i);
            else k++;
        }
        while(k--){
            res.push_back(0);
        }
        return res;
    }
};