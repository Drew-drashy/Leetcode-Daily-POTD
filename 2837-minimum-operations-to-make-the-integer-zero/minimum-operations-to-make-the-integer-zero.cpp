class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int ans = INT_MAX;
        for (int k = 1; k <= 60; k++) {
            long long S = 1LL * num1 - 1LL * k * num2;
            if (S >= k && __builtin_popcountll(S) <= k) {
                ans = min(ans, k);
            }
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};
