class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>ans;
        sort(folder.begin(),folder.end());
        ans.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string s=folder[i];
            string temp=ans.back()+"/";
            if(s.find(temp)!=0) ans.push_back(s);
        }
        return ans;
    }
};