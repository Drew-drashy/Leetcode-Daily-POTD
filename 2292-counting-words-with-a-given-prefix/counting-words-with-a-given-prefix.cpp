class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ind=0;

        for(string l : words){
            if(l.find(pref)==0) ind++;

        }
        return ind;
    }
};