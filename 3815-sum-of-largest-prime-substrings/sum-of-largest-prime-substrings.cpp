class Solution {
public:
    bool isPrime(long long n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (long long i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        unordered_set<long long> uniqueNumbers;

        // Generate all substrings and insert into the set
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            string sub = "";
            for (int j = i; j < len; ++j) {
                sub += s[j];
                long long num = stoll(sub); // handles leading zeros
                uniqueNumbers.insert(num);
            }
        }

        vector<long long> primes;
        for (auto num : uniqueNumbers) {
            if (isPrime(num)) {
                primes.push_back(num);
            }
        }

        // Sort in descending order
        sort(primes.rbegin(), primes.rend());

        long long sum = 0;
        for (int i = 0; i < min(3, (int)primes.size()); ++i) {
            sum += primes[i];
        }

        return sum;
    }
};
