class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;
        ans.push_back(words[0]);
        int gp=groups[0];
        int n=words.size();
        for(int i=1;i<n;i++){
            if(gp!=groups[i]){
                ans.push_back(words[i]);
                gp=groups[i];
            }
        }
        return ans;
    }
};