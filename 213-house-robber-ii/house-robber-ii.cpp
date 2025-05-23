class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 0) return 0;
        if (n == 1) return nums[start];

        vector<int> dp(n, 0);
        dp[n - 1] = nums[end];
        dp[n - 2] = max(nums[end - 1], nums[end]);

        for (int i = n - 3; i >= 0; --i) {
            dp[i] = max(nums[start + i] + dp[i + 2], dp[i + 1]);
        }

        return dp[0];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // Case 1: Exclude last house
        int option1 = robRange(nums, 0, n - 2);
        // Case 2: Exclude first house
        int option2 = robRange(nums, 1, n - 1);

        return max(option1, option2);
    }
};
