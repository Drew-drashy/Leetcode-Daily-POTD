class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(int i: nums) mp[i]++;
        int dis=mp.size();
        mp.clear();
        int i=0,j=0;
        int cnt=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()==dis){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
                cnt+=n-j;
            }
            j++;
        }
        return cnt;
    }
};