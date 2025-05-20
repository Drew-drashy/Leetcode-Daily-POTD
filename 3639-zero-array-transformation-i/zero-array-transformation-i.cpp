class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
       vector<int>ans(n+1,0);
       for(auto it: queries){
        ans[it[0]]++;
            if(it[1]+1<n){
                ans[it[1]+1]--;
            }
       }
        int cnt=0;
       for(int i=0;i<n;i++){
        cnt+=ans[i];
        if(nums[i]>cnt) return false;
       }
       return true;

    }
};