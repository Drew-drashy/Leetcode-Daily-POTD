class Solution {
public:
    bool static comp(string &a, string &b){
        return a>b;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        int n=words.size();
        // sort(words.begin(),words.end());
        for(string k : words) cout<<k<<" ";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( i!=j && words[j].find(words[i])!=string::npos ){
                    ans.push_back(words[i]);
                    break;
                }
            }

        }
        return ans;
    }
};