class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n==k) return true;
        if(k>n) return false;
        map<char,int>mp;
        for(char ch: s) mp[ch]++;
        int odd=0;
        for(auto it: mp){
            if(it.second%2) odd++;
        }
        if(odd==0) return true;
        if(odd<=k) return true;
        return false;
    }
};