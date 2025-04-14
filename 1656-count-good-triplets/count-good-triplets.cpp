class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n=arr.size();
        int mini=min({a,b,c});
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(abs(arr[i]-arr[j])<=a && abs(arr[j]-arr[k])<=b && abs(arr[i]-arr[k])<=c){
                        cnt++;
                    }
                }
            }
        }
        return cnt;

    }
};