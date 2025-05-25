class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        bool f=false;
        map<string,int>mp;
        for(auto it: words) mp[it]++;
        int ans=0;
        for(auto it: mp){
            string w=it.first;
            string k=it.first;
            int  cnt=it.second;
            reverse(k.begin(),k.end());
            if(w==k){
                if(cnt%2){
                    f=true;
                }
                int pairs=cnt/2;
                ans+=pairs*4;
                mp[w]=0;
            }
            else if(mp.find(k)!=mp.end()){
                int op=min(cnt,mp[k]);
                ans+=op*4;
                mp[w]=0;
                mp[k]=0;
            }


        }
        if(f) ans+=2;
        return  ans;
    }
};