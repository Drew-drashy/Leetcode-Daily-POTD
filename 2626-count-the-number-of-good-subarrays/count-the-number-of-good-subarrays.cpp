class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=0;
        map<int ,int>mp;
        int right=0;
        int left=0;
        long long op=0;
        while(right<n){
            ans+=mp[nums[right]];
            mp[nums[right]]++;
            while(ans>=k){
                op+=nums.size()-right;
                mp[nums[left]]--;
                ans-=mp[nums[left]];
                left++;
            }
right++;
        }
        return  op;

    }
};