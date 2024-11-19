class Solution {
public:
    bool static comp(string &a,string &b){
        return a.size()<b.size();
    }
    bool compare(string &a, string &b){
        if(a.size()+1!=b.size()) return false;
        long long i=0, j=0;
        while( j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
           else{
                j++;
            }
        }
        if(i>=a.size() && j>=b.size()) return true;
        else return false;
    }
    int longestStrChain(vector<string>& word) {
        int n=word.size();
        sort(word.begin(),word.end(),comp);
        for(string k: word) cout<<k<<" ";
        vector<int>dp(n,1);
        // return 0;
        int maxi=1;
        for(int ind=0;ind<n;ind++){
            for(int prev=0;prev<=ind-1;prev++){
                if( compare(word[prev],word[ind]) && dp[prev]+1>dp[ind] ){
                    dp[ind]=1+dp[prev];
                }
            }
            if(dp[ind]>maxi){
                maxi=dp[ind];
            }
        }
        return maxi;

    }
};