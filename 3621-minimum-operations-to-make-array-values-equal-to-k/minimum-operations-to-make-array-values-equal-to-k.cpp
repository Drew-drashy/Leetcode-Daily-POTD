class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        for(int i: nums){
            mp[i]++;

        }
        int cnt=0;
        for(auto it: mp){
            if(it.first>k){cnt++;}
            else if(it.first<k) return -1;
        }
        return cnt;
    }
};