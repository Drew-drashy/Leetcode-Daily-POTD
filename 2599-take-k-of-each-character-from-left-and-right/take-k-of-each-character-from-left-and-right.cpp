class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size();
        if(k==0) return k;
        if(n<3) return -1;
        int i=0;
        int j=0;
        ;
        vector<int>dp(3,0);
        for(char i: s) dp[i-'a']++;
        int mini=INT_MAX;
        while(i<=j && j<n){
            if(dp[0]>=k && dp[1]>=k && dp[2]>=k){
                mini=min(mini,n-j+i);
                dp[s[j++]-'a']--;
            }
            else{
                dp[s[i++]-'a']++;
            }
        }
        if( i<=j && dp[0]>=k && dp[1]>=k && dp[2]>=k){
                mini=min(mini,n-j+i);
                // dp[s[j++]-'a']++;
        }
        return mini==INT_MAX? -1: mini;

    }
};