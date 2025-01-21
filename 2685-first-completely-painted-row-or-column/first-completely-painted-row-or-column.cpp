class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        map<int,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        vector<int>row(n,m),col(m,n);
        for(int i=0;i<arr.size();i++){
            int val=arr[i];
            auto it=mp[val];
            int r=it.first;
            int c=it.second;
            if(--row[r]==0 || --col[c]==0) return i;
        }
        return -1;

    }
};