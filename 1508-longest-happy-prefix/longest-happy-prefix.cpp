class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        int length=0;
        vector<int>LPS(n);
        LPS[0]=0;
        int i=1;
        while(i<n){
            // cout<<"hi";
            if(s[i]==s[length]){
                length++;
                LPS[i]=length;
                i++;
            }
            else{
                if(length!=0){
                    length=LPS[length-1];
                }
                else{
                    LPS[i]=0;
                    i++;
                }
            }
        }
        int uy=*max_element(LPS.begin(),LPS.end());
        // if(uy==0) return "";
        return s.substr(0,LPS[n-1]);
    }
};