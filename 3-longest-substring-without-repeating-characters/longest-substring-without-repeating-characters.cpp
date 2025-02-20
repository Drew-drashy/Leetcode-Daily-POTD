class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n=s.size();
        map<char,int>mp;
        int maxi=0;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]>=2){
                if(mp[s[i]]==0) mp.erase(s[i]);
                mp[s[i]]--;
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
    
};