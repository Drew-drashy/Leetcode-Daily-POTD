class Solution {
public:
    bool isCircularSentence(string str) {
        stringstream s(str);
        vector<string> ans;
        string temp;
        
        while (s >> temp) {
            ans.push_back(temp);
        }
        
        int n = ans.size();
        if (n == 1) {
            string a = ans[0];
            return a[0] == a[a.size() - 1];
        }
        
        for (int i = 1; i < n; i++) {
            string a = ans[i - 1];
            string b = ans[i];
            if (a[a.size() - 1] != b[0]) {
                return false;
            }
        }
        
        string firstWord = ans[0];
        string lastWord = ans[n - 1];
        return lastWord[lastWord.size() - 1] == firstWord[0];
    }
};
