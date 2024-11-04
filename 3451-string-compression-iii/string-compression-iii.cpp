class Solution {
public:
    string compressedString(string word) {
        int n=word.size();
        string ans="";
        for(int i=0;i<n;i++){
        int cnt=1;
        char k=word[i];
        while(i+1<n && word[i]==word[i+1]) {cnt++,i++;}
        int rem=cnt%9;
        int val=cnt/9;
        while(val--){
            ans+=to_string(9)+k;
        }
        if(rem!=0) ans+=to_string(rem)+k;
        }
        return ans;
    }
};