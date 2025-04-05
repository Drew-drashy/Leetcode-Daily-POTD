class Solution {
public:
    int fun(int ind,vector<int>&nums,int c){
        int n=nums.size();
        if(ind==n) return c;
        int a=fun(ind+1,nums,c^nums[ind]);
        int b=fun(ind+1,nums,c);
        return a+b;
    }
    int subsetXORSum(vector<int>& nums) {
        return fun(0,nums,0);
    }
};