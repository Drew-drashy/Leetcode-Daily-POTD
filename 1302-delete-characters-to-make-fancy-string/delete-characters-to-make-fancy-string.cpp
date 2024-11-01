class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        stack<pair<char,int>>st;
 
        for(int i=0;i<n;i++){
            // st.push(s[i]);
            if(!st.empty() && s[i]==st.top().first){
                st.top().second++;
            }
            else{
                st.push({s[i],1});
            }
            if(st.size() && st.top().second==3){
                st.top().second--;
            }
        }
        string str="";
        while(!st.empty()){
            str+=string(st.top().second,st.top().first);
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};