class Solution {
public:
    int fun(vector<int>&tops,vector<int>&bottoms,int target){
        int t=0;
        int b=0;
        for(int i=0;i<tops.size();i++){
            if(tops[i]!=target && bottoms[i]!=target) return INT_MAX;
            if(tops[i]!=target) t++;
            if(bottoms[i]!=target) b++;
        }
        return min(t,b);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans= fun(tops,bottoms,tops[0]);
        int bns=fun(tops,bottoms,bottoms[0]);
        if(ans==bns && ans==INT_MAX) return -1;
        return min(ans,bns);
        // return ans==INT_MAX? -1: ans;
    }
};