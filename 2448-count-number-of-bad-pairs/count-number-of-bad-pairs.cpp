class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long  n=nums.size();
        long long  op=(n*(n-1))/2;
        map<long , long >mp;
        long long cnt=0;
        for(int i=0;i<n;i++){
            long long ans=nums[i]-i;
            cnt+=mp[ans];
            mp[ans]++;
        }
        return op-cnt;
    }  

    
    
};

