class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        int n=nums.size();
        int i=0,j=0;
        long long sum=0;
        long long cnt=0;
        while(j<n){
            sum+=nums[j];
            ans=sum*(j-i+1);
            while(ans>=k){
                sum-=nums[i];
                i++;
                ans=sum*(j-i+1);
            }
            if(ans<k) cnt+=j-i+1;
            j++;
        }
    
        return cnt;
    }
};