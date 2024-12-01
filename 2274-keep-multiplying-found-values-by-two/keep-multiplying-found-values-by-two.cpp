class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>mp;
        for(int i: nums) mp.insert(i);
        while(mp.find(original)!=mp.end()){
            original*=2;
        }
        return original;
    }
};