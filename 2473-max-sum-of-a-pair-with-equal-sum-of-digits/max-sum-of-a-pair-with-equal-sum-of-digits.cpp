class Solution {
public:
    int fun(string ans){
        int cnt=0;
        for(char k : ans){
            cnt+=k-'0';
        }
        return cnt;
    }
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        int maxi=-1;
        for(int i: nums){
            string ans=to_string(i);
            int num=fun(ans);
            if(mp.find(num)!=mp.end()){
                int val=mp[num];
                maxi=max(maxi,val+i);
                mp[num]=max(val,i);
            }
            else{
                mp[num]=i;
            }
        }
        return maxi;
    }
};