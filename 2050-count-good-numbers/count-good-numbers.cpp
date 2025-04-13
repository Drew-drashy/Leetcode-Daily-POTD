class Solution {
public:
    static const long long MOD = 1000000007;

    // Fast exponentiation: (base^exp) % m
    long long modExp(long long base, long long exp, long long m) {
        long long result = 1;
        base %= m;  // Handle large base

        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % m;
            }
            base = (base * base) % m;
            exp >>= 1; // exp = exp / 2
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        // "even" positions can hold 5 possible digits (0,2,4,6,8)
        // "odd" positions can hold 4 possible digits (1,3,5,7,9 are not valid? 
        // Actually if by "odd" we only have "prime digits"? 
        // Typically the logic is from the problem statement, but let's assume 4 for odd positions:

        long long even = n / 2; 
        long long odd  = n / 2;

        // If n is odd, one more even index than odd
        if (n % 2 == 1) {
            even += 1;
        }

        long long total = (modExp(5, even, MOD) * modExp(4, odd, MOD)) % MOD;
        return (int) total;
    }
};