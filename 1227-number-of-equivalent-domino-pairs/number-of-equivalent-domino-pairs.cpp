class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        int cnt=0;
        map<pair<int,int>,int>mp;
        for(auto it: dominoes){
            // if(it[0]>it[1]) swap(it[0],it[1]);
            cnt+=mp[{max(it[0],it[1]),min(it[0],it[1])}]++;
        }
        return cnt;
    }
};