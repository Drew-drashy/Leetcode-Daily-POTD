class Solution {
public:
    void fun(int open,int close,string s,vector<string>&ans,int n){
        if(open==n && close==n){
            ans.push_back(s);
            return;
        }
        if(open!=n){
            fun(open+1,close,s+"(",ans,n);
        }
        if(open>close){
            fun(open,close+1,s+")",ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string k;
        fun(0,0,k,ans,n);
        return ans;
    }
};