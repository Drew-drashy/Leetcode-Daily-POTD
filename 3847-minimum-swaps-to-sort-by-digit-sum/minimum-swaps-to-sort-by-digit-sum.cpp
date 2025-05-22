class Solution {
public:
    int findsum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
       vector<pair<int,int>>arr;
       vector<int>visited(n,0);
       for(int i=0;i<n;i++){
        arr.push_back({nums[i],i});

       }
       sort(arr.begin(),arr.end(),[&](auto a,auto b){
        int sum1=findsum(a.first);
        int sum2=findsum(b.first);
        if(sum1==sum2) return a.first<b.first;
        return sum1<sum2;
       });
       int cnt=0;
       for(int i=0;i<n;i++){
            if(visited[i] || arr[i].second==i) continue;

            int j=i;
            int cycle=0;
            while(!visited[j]){
                visited[j]=1;
                j=arr[j].second;
                cycle++;
            }
            if(cycle>1){
                cnt+=(cycle-1);
            }
       }
       return cnt;
       
    }
};