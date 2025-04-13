class Solution {
public:
    static const long long MOD = 1000000007;

    
    long long modExp(long long base, long long exp, long long m) {
       if(exp==0) return 1;
       if(base==0 || base==1) return base;
       if(exp%2==0){
        long long temp=modExp(base,exp/2,m);
        return (temp*temp)%m;
       }

       return (base*modExp(base,exp-1,m))%m;
    }


    int countGoodNumbers(long long n) {
        long long even = n / 2; 
        long long odd  = n / 2;
        if (n % 2 == 1) {
            even += 1;
        }

        long long total = (modExp(5, even, MOD) * modExp(4, odd, MOD)) % MOD;
        return (int) total;
    }
};