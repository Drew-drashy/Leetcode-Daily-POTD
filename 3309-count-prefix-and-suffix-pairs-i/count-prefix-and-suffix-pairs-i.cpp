class Solution {
public:
    bool fun(string &a, string &b){
        int n=a.size();
        
        int m=b.size();
        if(n>m) return false;
        string k=b.substr(0,n);
        string p=b.substr(m-n);
        cout<<k<<" "<<p<<"\n";
        if(a==k && a==p) return true;
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(fun(words[i],words[j])){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};