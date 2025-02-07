class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    //       5 ball
    //       0 1 2 3 4 
    //       - - - - -
    // q
    // 1     - 4 - - -  1    
    // 2    -  4 5 - -   2
    // 3    -  3 5 - -   2 
    // 4    -  3 5 4 -    3

    //            0 1 2 3 4
    // 1          1 - - - -
    // 2          1 2 - - -
    // 3          1 2 2 - -
    // 4          1 2 2 4 -
    // 5          1 2 2 4 5
    int n=queries.size();
    vector<int>res;
    map<int,int>mp;
    map<int,set<int>>mpp;

    
    for(auto it: queries){
        int a=it[0];
        int b=it[1];
        if(mp.find(a)==mp.end()){
           mp[a]=b;
           mpp[b].insert(a);
        }
        else{
           int c=mp[a];
           mpp[c].erase(a);
           if(mpp[c].empty()){
            mpp.erase(c);
           }
           mpp[b].insert(a);
           mp[a]=b;
        }
        // mp[a]=b;
        res.push_back(mpp.size());
    }
    return res;
    // /


    }
};