class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;
        priority_queue<int>pq;
        for(int i: gifts) pq.push(i);
        while(k--){
            int num=pq.top();
            pq.pop();
            cout<<num<<" ";
            int val=pow(num,0.5);
            if(val!=0) pq.push(val);
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};