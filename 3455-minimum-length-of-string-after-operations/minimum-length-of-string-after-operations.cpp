class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        if(n<=2) return n;
        map<char,int>mp;
        for(char i: s){
            mp[i]++;

        }
        for(auto it: mp) cout<<it.second<<" ";
        for(auto it: mp){
            int val=it.second;
            while(val>2){
                val-=2;
            }
            mp[it.first]=val;

        }
        int cnt=0;
        for(auto it: mp) cnt+=it.second;
        return cnt;
    }
};