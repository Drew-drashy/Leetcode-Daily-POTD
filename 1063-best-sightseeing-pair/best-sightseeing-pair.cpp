class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int maxi=0;
        int m=values[0]+0;
        for(int i=1;i<n;i++){
            maxi=max(maxi,m+values[i]-i);
            if(values[i]+i>m) m=i+values[i];
        }
        return maxi;

    }
};