class Solution {
public:
    // Convert string to number safely (avoid pow)
    long long convert(const string &k) {
        long long ans = 0;
        for (char ch : k) {
            ans = ans * 10 + (ch - '0');
        }
        return ans;
    }

    // Check if a number is prime
    bool check(long long num) {
        if (num < 2) return false;
        for (long long i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        unordered_set<long long> seen;
        vector<long long> primes;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n - i; j++) {
                string k = s.substr(i, j);
                long long num = convert(k);
                if (seen.count(num) == 0) {
                    seen.insert(num);
                    if (check(num)) {
                        primes.push_back(num);
                    }
                }
            }
        }

        if (primes.empty()) return 0;

        // Sort descending to get top 3 primes
        sort(primes.rbegin(), primes.rend());

        long long sum = 0;
        for (int i = 0; i < min(3, (int)primes.size()); ++i) {
            sum += primes[i];
        }

        return sum;
    }
};
