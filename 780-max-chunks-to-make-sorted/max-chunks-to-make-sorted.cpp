class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int>temp(n,0);
        vector<int>sum(n,0);
        sum[0]=arr[0];
        for(int i=1;i<n;i++){
            sum[i]=arr[i]+sum[i-1];
        }
        for(int i=0;i<n;i++){
            temp[i]=(i*(i+1))/2;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(sum[i]==temp[i]) cnt++;
        }
        return cnt;
    }
};