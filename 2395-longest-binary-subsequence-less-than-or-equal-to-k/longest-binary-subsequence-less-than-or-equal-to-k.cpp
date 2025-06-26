class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.size();
        int bits=0;
        int val=0;
        int cnt=0;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                cnt++;
            }
            else{
                if(bits<31){
                    long add=1L<<bits;
                    if(val+add<=k){
                        val+=add;
                        cnt++;
                    }
                }
            }
            bits++;
        }
        return cnt;
    }
};