class Solution {
public:
    bool isCircularSentence(string str) {
        int n=str.size();
        if(str[0]!=str[n-1])  return false;
        for(int i=1;i<n-1;i++){
            if(str[i]==' '){
                if(str[i-1]!=str[i+1]) return false;
            }
        }
        return true;
    }
};