class Solution {
public:
    vector<int> dp;
    
    bool func(string& str, int min_j, int max_j, int i) {
        int n = str.size();
        if (i == n - 1)
            return true;

        if (dp[i] != -1)
            return dp[i];

        bool ans = false;
        for (int j = max_j; j >= min_j; j--) {
            if (i + j < n && str[i + j] == '0') {
                ans = ans || func(str, min_j, max_j, i + j);
                if (ans)
                    break; 
            }
        }
        return dp[i] = ans;
    }
    
    bool canReach(string s, int minJump, int maxJump) {
        if (s[s.length() - 1] == '1')
            return false;

        dp = vector<int>(s.length(), -1); // Adjusted to s.length()

        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                cnt++;
                if (cnt >= maxJump)
                    return false;
            } else
                cnt = 0;
        }
        return func(s, minJump, maxJump, 0);
    }
};