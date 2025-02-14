class Solution {
    #define MOD 1000000007

public:
    int sumOfFlooredPairs(vector<int>& nums) {
    int maxNum = *max_element(nums.begin(), nums.end());
    vector<int> freq(maxNum + 1, 0);

    // Step 1: Count frequency of each number
    for (int num : nums) {
        freq[num]++;
    }

    // Step 2: Compute prefix sums
    vector<int> prefix(maxNum + 1, 0);
    for (int i = 1; i <= maxNum; i++) {
        prefix[i] = prefix[i - 1] + freq[i];
    }

    // Step 3: Compute sum using a DP-style approach
    long long result = 0;
    for (int i = 1; i <= maxNum; i++) {
        if (freq[i] == 0) continue;
        long long sumFloors = 0;

        // Step 4: Compute floor(y / i) * freq[y] using a DP-like iteration
        for (int multiple = i; multiple <= maxNum; multiple += i) {
            int left = multiple, right = min(multiple + i - 1, maxNum);
            sumFloors += (long long)(prefix[right] - prefix[left - 1]) * (multiple / i);
            sumFloors %= MOD;
        }

        result = (result + sumFloors * freq[i]) % MOD;
    }

    return result;
}
};