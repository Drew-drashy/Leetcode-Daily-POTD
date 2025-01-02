class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<char> vow = {'a', 'e', 'i', 'o', 'u'};
        vector<int> pre(n + 1, 0), ans;

        // Build prefix sum array
        for (int i = 1; i <= n; ++i) {
            int sz = words[i - 1].length();
            int val = (find(vow.begin(), vow.end(), words[i - 1][0]) != vow.end() &&
                       find(vow.begin(), vow.end(), words[i - 1][sz - 1]) != vow.end());
            pre[i] = pre[i - 1] + val;
        }

        // Process each query
        for (int i = 0; i < queries.size(); ++i) {
            int l = queries[i][0], r = queries[i][1];
            ans.push_back(pre[r + 1] - pre[l]);
        }

        return ans;
    }
};