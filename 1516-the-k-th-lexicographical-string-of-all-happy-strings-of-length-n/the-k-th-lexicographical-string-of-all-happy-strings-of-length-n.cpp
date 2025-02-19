class Solution {
public:
    void fun(int i,int j,int n,string &res,vector<string>&ans){
        //  cout<<res<<" ";
        if(i>=n){
            ans.push_back(res);
            return ;
        }
       
        if(j==-1){
            for(char t='a';t<='c';t++){
                res+=t;
                // ans.push_back(res);
                fun(i+1,i,n,res,ans);
                res.pop_back();
            }
        }
        else{
            for(char t='a';t<='c';t++){
                if(res[j]!=t){
                    res+=t;
                    // ans.push_back(res);
                    fun(i+1,i,n,res,ans);
                    res.pop_back();
                }
            }
            
        }
    }
    string getHappyString(int n, int k) {
        string res="";
        vector<string>ans;
        fun(0,-1,n,res,ans);
        // cout<<"outer";
        sort(ans.begin(),ans.end());
        n=ans.size();
        if(n<=k-1) return "";
        return ans[k-1];
    }
};