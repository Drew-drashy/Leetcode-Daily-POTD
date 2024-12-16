class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        vector<int>ans(n,0);
        // 2,0  1,1  3,2  5,3  6,4  
        //       2
        //  4
        //        4    
        //             6
        //   8               
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(k--){
            auto it=pq.top();
            int val=it.first;
            int ind=it.second;
            pq.pop();
            pq.push({val*multiplier,ind});
        }
        while(!pq.empty()){
            auto it=pq.top();
            int val=pq.top().first;
            int ind=pq.top().second;
            ans[ind]=val;
            pq.pop();
        }

        return ans;
    }
};