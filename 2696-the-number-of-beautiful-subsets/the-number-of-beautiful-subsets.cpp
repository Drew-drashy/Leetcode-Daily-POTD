class Solution {
public:
    bool checker(vector<int>&a,int k,int val){
        for(int i: a){
            if(abs(i-val)==k) return false;
        }
        return true;
    }
    int cnt=-1;
    void fun(int ind,int k,vector<int>&nums,vector<int>&ans){
        if(ind>=nums.size()){
            cnt++; 
            return;
        }
        fun(ind+1,k,nums,ans);
        if(checker(ans,k,nums[ind])){
            ans.push_back(nums[ind]);
            fun(ind+1,k,nums,ans);
            ans.pop_back();
        }
        

    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int>ans;
        fun(0,k,nums,ans);

        return cnt; 
    }
};