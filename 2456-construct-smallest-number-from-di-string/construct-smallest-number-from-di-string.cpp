class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size();
        stack<int>st;
        string res="";

        for(int i=0;i<=n;i++){
            st.push(i+1);
            if(pattern[i]=='I' || i==pattern.size()){
                while(!st.empty()){
                    res+=to_string(st.top());
                    st.pop();
                }
            }
        }
        return res;
    }
};