class Solution {
public:
    int minimumDeletions(string s) {
        int cnt=0;
        int b=0;
        for(char i: s){
            if(i=='a') cnt=min(cnt+1,b);
            else b++;
        }return cnt;
    }
};