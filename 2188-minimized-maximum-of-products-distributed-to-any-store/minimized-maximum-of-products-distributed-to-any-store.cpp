class Solution {
public:
    bool fun(int n,vector<int>&arr,int mid){
        int val=0;
        if(mid==0) return false;
        for(int i: arr){
            val+=(i+mid-1)/mid;
            if(val>n) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& arr) {
        int m=arr.size();
        int low=0;
        int high=*max_element(arr.begin(),arr.end());
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(fun(n,arr,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;

    }
};