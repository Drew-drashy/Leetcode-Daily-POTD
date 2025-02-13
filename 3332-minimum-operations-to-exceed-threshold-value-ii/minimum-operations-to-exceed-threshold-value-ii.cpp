class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long long,vector<long long>,greater<long long >>pq;
        for(int i: nums) pq.push(i);
        int cnt=0;
        while(!pq.empty()){
            long long int a=pq.top();
            if(a>=k) return cnt;
            pq.pop();
            long long int b=pq.top();
            pq.pop();
            long long int  val=min(a,b)*2+max(a,b);
            pq.push(val);
            cnt++;

        }
        return 0;
    }
};