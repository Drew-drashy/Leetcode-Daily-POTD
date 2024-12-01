class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int>mp;
         for(int i: arr) mp[i]++;
         for(int i: arr){
            if((i==0 || i==1) && mp[i]>1) {cout <<i<<" "<<mp[i];return true;}
            else if( i!=0 && i!=1 && mp.find(2*i)!=mp.end()) {cout <<i;return true;}
         }
         return false;
    }
};