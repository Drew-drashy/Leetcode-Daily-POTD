class Solution {
public:
    void LPS(string&str, vector<int>&lps){
        int len=0;
        int i=1;
        lps[0]=0;
        while(i<str.size()){
            if(str[i]==str[len]){
               
                len++;
                lps[i]=len;
                 i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }

    }
    bool fun(string &str, string &target){
        int n=str.size();
        int m=target.size();
        int i=0,j=0;
        vector<int>lps(n,0);
        LPS(str,lps);
        while(i<n){
            if(target[j]==str[i]){
                i++;
                j++;

            }
            if(j==m) return true;
            else if(i<n && target[j]!=str[i]){
                if(j!=0) j=lps[j-1];
                else i++;
            }
        }
        return false;
    }

    vector<int> findWordsContaining(vector<string>& words, char x) {
        // lets do this question with the LPS.....
        int n=words.size(); 
        vector<int>ans;
        for(int i=0;i<n;i++){
            string target(1,x);
            if(fun(words[i],target)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};