class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>f1(51,0);
        vector<int>f2(51,0);
        vector<int>ans(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            int a=A[i];
            int b=B[i];
            f1[a]++;
            f2[b]++;
            int cnt=0;
            for(int i=1;i<=50;i++){
                if(f1[i]&&f2[i]) cnt++;
            }
            ans[i]=cnt;
        }
        return ans;

    }
};