class Solution {
public:
    int possibleStringCount(string word) {
        char t=word[0];
        int ans=1;
        for(int i=1;i<word.size();i++){
            if(t==word[i]) ans++;
            else t=word[i];
        }
        return ans;
    }
};