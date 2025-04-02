class Solution {
public:
    long long maximumTripletValue(vector<int>&nums){
        int n=nums.size();
        long long ans=LLONG_MIN;
        long long max_i=0;
        long long bestdiff=0;
        for(int i: nums){
            ans=max(ans,bestdiff*i);
            bestdiff=max(bestdiff,max_i-i);
            max_i=max(max_i,(long long )i);
        }
        return ans;
    }
};