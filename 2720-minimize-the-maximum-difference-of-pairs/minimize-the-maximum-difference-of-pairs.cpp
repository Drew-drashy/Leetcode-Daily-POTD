class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0) return 0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums[n-1]-nums[0];
        
        while(left<right){
            int mid=(right+left)/2;
            int pair=0;
            for(int i=1;i<n;i++){
                if(nums[i]-nums[i-1]<=mid){
                    pair++;
                    i++;
                }
            }
            if(pair>=p) right=mid;
            else left=mid+1;

        }
        return left;
    }
};