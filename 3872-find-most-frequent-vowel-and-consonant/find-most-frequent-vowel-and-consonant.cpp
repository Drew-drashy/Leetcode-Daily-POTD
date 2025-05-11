class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int>mp;
        for(char i: s) mp[i]++;
        int maxi=0,maxi2=0;
        for(auto it: mp){
            if(it.first=='a' || it.first=='e' || it.first=='o' || it.first=='i' || it.first=='u'){
                maxi=max(maxi,it.second);
            }
            else{
                maxi2=max(maxi2,it.second);
            }
        }
        return maxi+maxi2;
    }
};