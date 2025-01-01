class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int maxi=0;
        int l=0;int r=0;
        int p=0;
        int k=0;
        for(char i: s){
            if(i=='1') p++;
            else k++;
        }
        if(p==n || k==n) return n-1;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0') l++;
            else r++;
            maxi=max(maxi,l-r+p);
        }
        return maxi;
    }
};