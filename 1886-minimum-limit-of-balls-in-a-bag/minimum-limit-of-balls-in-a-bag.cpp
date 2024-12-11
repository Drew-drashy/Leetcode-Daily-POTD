class Solution {
public:
bool isValid(vector<int>&nums,int maxop,int mid){
    priority_queue<int>pq;
    for(int&x:nums)pq.push(x);
    while(!pq.empty()){
        int val=pq.top();pq.pop();
        if(val<=mid)return 1;
        int cnt=val/mid;// val mein se har bar mid val nikalne ke liye ye op
        // yani jitne val mein mid honge -> utne operations
        // par agar wo aek factor hai to last me jab hum do bhago mein tordenge to doo mid aa jayenge
        // par agr factor na hua to , aek operation or lagega!
        if(val%mid==0)cnt--;
        if(maxop>=cnt)maxop-=cnt;
        else return 0;
        
    }
    if(pq.empty())return 1;
    if(pq.top()<=mid)return 1;return 0;
}
    int minimumSize(vector<int>& nums, int maxop) {
        int n=nums.size();
        int l=1,h=INT_MAX-1000,ans=INT_MAX;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isValid(nums,maxop,mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};