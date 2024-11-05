class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        if(n==2){
            if(s[0]==s[1]) return 0;
            else return 1;
        }
        int cnt=0;
        for(int i=0;i<n-1;i+=2){
            int j=i+1;
            if(s[i]!=s[j]) cnt++;
            // i+=2;
        }
        return cnt;
    }
};