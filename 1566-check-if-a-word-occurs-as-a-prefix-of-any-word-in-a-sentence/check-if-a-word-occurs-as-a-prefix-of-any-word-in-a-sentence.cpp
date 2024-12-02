class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream stream(sentence);
        string word;
        int ind=1;
        while(stream>>word){
            if(word.find(searchWord)==0) return ind;
            ind++;

        }
        return -1;

    }
};