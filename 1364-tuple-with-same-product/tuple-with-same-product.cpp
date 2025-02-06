class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        int ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int prod=nums[i]*nums[j];
                ans+=(mp[prod]*8);
                mp[prod]++;
            }   
        }
        return ans;
    }
};