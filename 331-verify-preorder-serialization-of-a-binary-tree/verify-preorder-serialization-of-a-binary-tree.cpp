class Solution {
public:
    bool isValidSerialization(string preorder) {

        stack<string>st;
        stringstream s(preorder);
        string i;
        while(getline(s,i,',')){
           if(st.empty() || i!="#") st.push(i);
           else{
                while(!st.empty() && st.top()=="#"){
                    st.pop();
                    if(st.empty()) return false;
                    else st.pop();
                }
                st.push(i);
           }
        }
        return st.size()==1 && st.top()=="#";



    }
};