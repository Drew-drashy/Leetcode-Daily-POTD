class Solution {
public:
    long minEnd(int n, int x) {
        long long a=x;
        n--;
        while(n--){
            a=(a+1)|x;
 
        }
        return a;    }
};