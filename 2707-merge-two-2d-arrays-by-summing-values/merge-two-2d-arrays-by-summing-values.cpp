class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        vector<vector<int>>ans=nums1;
        map<int,int>mp;
        for(auto it: ans){
            mp[it[0]]+=it[1];
        }
        ans.clear();
        for(auto it: mp){
            ans.push_back({it.first,it.second});
        }
        return ans;
        

    }
};