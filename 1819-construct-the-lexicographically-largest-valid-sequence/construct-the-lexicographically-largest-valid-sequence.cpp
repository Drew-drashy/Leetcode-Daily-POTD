class Solution {
public:

    bool fun(int i, int n, vector<int>&result,vector<bool>&used){
        int len=result.size();
        if(i>=len) return true;
        if(result[i]!=0) return fun(i+1,n,result,used);
        for(int ind=n;ind>=1;ind--){
            if(used[ind])  continue;

            if(ind==1){
                result[i]=ind;
                used[ind]=true;
                if(fun(i+1,n,result,used)) return true;
                result[i]=0;
                used[1]=false;
            }
            else if(i+ind<len && result[i+ind]==0){
                result[i]=ind;
                result[i+ind]=ind;
                used[ind]=true;
                if(fun(i+1,n,result,used))return true;
                result[i]=0;
                result[i+ind]=0;
                used[ind]=false;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        // backtrack(result, used, n, 0);
        bool k=fun(0,n,result,used);
        return result;
    }

private:
    // bool backtrack(vector<int>& result, vector<bool>& used, int n, int index) {
    //     while (index < result.size() && result[index] != 0) {
    //         index++;
    //     }
    //     if (index == result.size()) {
    //         return true;
    //     }

    //     for (int i = n; i >= 1; i--) {
    //         if (used[i]) continue;

    //         if (i == 1) {
    //             result[index] = 1;
    //             used[1] = true;
    //             if (backtrack(result, used, n, index + 1)) return true;
    //             result[index] = 0;
    //             used[1] = false;
    //         } else if (index + i < result.size() && result[index + i] == 0) {
    //             result[index] = i;
    //             result[index + i] = i;
    //             used[i] = true;
    //             if (backtrack(result, used, n, index + 1)) return true;
    //             result[index] = 0;
    //             result[index + i] = 0;
    //             used[i] = false;
    //         }
    //     }
    //     return false;
    // }
};