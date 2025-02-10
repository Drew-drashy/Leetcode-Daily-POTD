class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(char i: s){
            if(!isdigit(i)){
                st.push(i);
            }
            else{
                if(!st.empty() && !isdigit(st.top())){
                    st.pop();
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};