class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int n = nums.size(), ans = 0, MOD = 1e9+7;
        unordered_map<int, int> count; // Tracks prefix sum parity count
        count[0] = 1; // Initial even count (sum = 0)
        
        int sum = 0;
        for (int num : nums) {
            sum += num;
            int parity = sum % 2; // 0 for even, 1 for odd
            
            // If sum is odd, count previous even sums
            ans = (ans + count[1 - parity]) % MOD;
            
            // Update count of current parity
            count[parity]++;
        }
        return ans;
    }
};