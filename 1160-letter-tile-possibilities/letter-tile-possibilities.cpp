class Solution {
public:
    void backtrack(int &count, map<char, int> &mp) {
        for (auto &it : mp) {
            if (it.second == 0) continue;
            it.second--;
            count++;
            backtrack(count, mp);
            it.second++;
        }
    }

    int numTilePossibilities(string tiles) {
        map<char, int> mp;
        for (char c : tiles) {
            mp[c]++;
        }
        int count = 0;
        backtrack(count, mp);
        return count;
    }
};
