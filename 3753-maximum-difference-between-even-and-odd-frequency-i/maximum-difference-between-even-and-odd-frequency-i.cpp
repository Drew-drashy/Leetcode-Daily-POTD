class Solution {
public:
    int maxDifference(string s) {
        int maxi=0;
        int mini=INT_MAX;
        vector<int>freq(26,0);
        for(char i: s) freq[i-'a']++;

        // for(int i=0;i<26;i++) cout<<freq[i]<<" ";

        // cout<<"\n";
        for(int i=0;i<26;i++){
            if(freq[i]%2){
                maxi=max(maxi,freq[i]);
            }
            if( freq[i] !=0 && freq[i]%2==0){
                mini=min(mini,freq[i]);
            }
        }
        // cout<<maxi<<" "<<mini;
        return maxi-mini;

    }
};