class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool>ans;
        int n=nums.size();
        set<int>st;
        for(int i=1;i<n;i++){
            if(nums[i-1]%2==nums[i]%2) st.insert(i);
        }
        for(auto it: queries){
            int a=it[0];
            int b=it[1];
            auto kt=st.upper_bound(a);
            ans.push_back((*kt<=b && kt!=st.end())  ? 0: 1);
        }
        return ans;
    }
};