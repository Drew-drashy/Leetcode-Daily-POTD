class Solution {
public:
    // Function to check if two strings have Hamming distance 1
    bool validHammingDistance(const string& a, const string& b) {
        if (a.size() != b.size()) return false;
        
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) diff++;
            if (diff > 1) return false;
        }
        return diff == 1;
    }
    
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);  // Length of longest valid subsequence ending at index i
        vector<int> prev(n, -1);  // Previous index in the optimal subsequence
        
        int maxLen = 1;
        int endIndex = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Check if we can extend the subsequence
                if (groups[i] != groups[j] && validHammingDistance(words[i], words[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                endIndex = i;
            }
        }
        
        // Reconstruct the subsequence
        vector<string> result;
        while (endIndex != -1) {
            result.push_back(words[endIndex]);
            endIndex = prev[endIndex];
        }
        
        // Reverse to get the correct order
        reverse(result.begin(), result.end());
        return result;
    }
};