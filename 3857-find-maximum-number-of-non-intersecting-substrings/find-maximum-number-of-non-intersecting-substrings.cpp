class Solution {
public:
    int maxSubstrings(string word) {
        // converting this question into merge intervals;
        map<char,int>mp;
        int  cnt=0;
        int n=word.size();
       for(int i=0;i<n;i++){
            
            if(mp.find(word[i])==mp.end()){
                mp[word[i]]=i;
            }
            else{
                if(i-mp[word[i]]+1>=4){
                    cnt++;
                    mp.clear();

                }
            }
            // mp[word[i]]=i;
       }
       return cnt;
        
        
    }
};