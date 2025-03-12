class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cnt=0;
        int mnt=0;
        int maxi=0;
        for(int i: nums){
            if(i>0) cnt++;
            if(i<0) mnt++;
            maxi=max({cnt,maxi,mnt});


        }
        return maxi;
    }
};