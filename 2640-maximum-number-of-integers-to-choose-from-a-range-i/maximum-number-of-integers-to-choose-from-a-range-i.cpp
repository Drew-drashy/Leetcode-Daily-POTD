class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st;
        for(int i: banned) st.insert(i);
        int sum=0;
        int k=0;
        for(int i=1;i<=n;i++){
            if(st.count(i)==0){
                if(sum+i<=maxSum){
                    sum+=i;
                    k++;
                }
            }
        }
        return k;
    }
};