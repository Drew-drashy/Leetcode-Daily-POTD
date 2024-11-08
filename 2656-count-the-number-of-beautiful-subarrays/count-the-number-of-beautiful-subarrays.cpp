class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        // if(n==1){
        //     if(nums[0]==0) return 1; 
        // }
        map<int,int>mp;

        mp[0]=1;
    int x=0;
        for(int i=0;i<n;i++){
            x^=nums[i];
            ans+=mp[x];
            mp[x]++;
        }
        return ans;
        
    }
};