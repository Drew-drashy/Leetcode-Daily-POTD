class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int k=0;
        for(int t: nums){
            pq.push({t,k++});
        }
        long long ans=0;
        while(!pq.empty()){
            int ind=pq.top().second;
            int val=pq.top().first;
            pq.pop();
            if(nums[ind]!=-1){
                ans+=val;
                if(ind>=1 && ind<=n-2){
                    nums[ind+1]=-1;
                    nums[ind-1]=-1;
                }
                else if(ind ==0){
                    nums[ind+1]=-1;
                }
                else{
                    nums[ind-1]=-1;
                }
            }

        }
        return ans;
    }
};