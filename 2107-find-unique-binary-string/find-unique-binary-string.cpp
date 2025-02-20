class Solution {
public:
    vector<string>ans;
    void fun(int ind,int n,string &res,map<string,int>&mp){
        if(ind>=n){
            ans.push_back(res);
            return;
        }
        for(char i='0';i<='1';i++){
            res+=i;
            fun(ind+1,n,res,mp);
            res.pop_back();
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        map<string,int>mp;
        for(string i: nums) mp[i]++;
        int m=nums[0].size();
        string res="";
        fun(0,n,res,mp);
        // for(string l: ans) cout<<l;
        for(string k: ans){
            if(mp.find(k)==mp.end()) return k;
        }
        return "";
    }
};