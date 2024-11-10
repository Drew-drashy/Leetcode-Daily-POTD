class Solution {
public:
    void fun(vector<int>&hash,int num,int cnt){
        // int cnt=1;
        for(int i=0;i<32;i++){
            if((num>>i)&1){
                hash[i]+=cnt;
            }
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>hash(32,0);
        int len=INT_MAX;
        int i=0,j=0;
        while(j<n){
            fun(hash,nums[j],1);
            while(i<=j && getVal(hash)>=k){
                len=min(len,j-i+1);
                fun(hash,nums[i],-1);
                i++;
            }
            j++;
        }
        if(len==INT_MAX) return -1;
        return len;
    }
    int getVal(vector<int>&nums){
        int ans=0;
        for(int i=0;i<32;i++){
            if(nums[i]>0){
                ans|=(1<<i);
            }
        }
        return ans;
    }
};