class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        int i=0,j=0;
        long long cnt=0;
        int maxi=-1;
        int mini=-1;
        // int i=0;
        while(j<n){
            int val=nums[j];
            if(val<minK || val>maxK){
                i=j+1;
            }
            if(val==maxK) maxi=j;
            if(val==minK) mini=j;
            cnt+=max(min(maxi,mini)-i+1,0);
            j++;

        }
        return cnt;
        
    }
};