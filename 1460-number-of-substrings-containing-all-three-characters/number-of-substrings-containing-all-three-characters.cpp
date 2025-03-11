class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int i=0,j=0;
        map<char,int>mp;
        int cnt=0;
        while(j<n){
            mp[s[j]]++;
            
                while(mp.size()==3){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    cnt+=n-j;
                    i++;
                }
            
            j++;
        }
        return cnt;
    }
};