class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<string> st;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if ((ch >= 'a' && ch <= 'z') || ch == '(') {
                st.push(string(1, ch));
            }
            else if (ch == ')') {
                string temp = "";
                // Collect and reverse contents inside the current parentheses
                while (!st.empty() && st.top() != "(") {
                    temp += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // Pop the '('
                reverse(temp.begin(), temp.end()); // Reverse the collected string
                st.push(temp);
            }
        }

        string result = "";
        while (!st.empty()) {
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());

        return result;
    }
};
