class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans(prices.begin(),prices.end());
        int n=prices.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(prices[i]>=prices[j]){
                    ans[i]=prices[i]-prices[j];
                    break;
                }
            }
        }
        return ans;
    }
};