class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<long long >st;
        for(int i: nums) st.insert(i);
        int maxi=-1;
        for(int i :nums){
           long long  val=i;
           int cnt=0;
           while(st.find(val)!=st.end()){
            val=pow(val,2);
            cnt++;
           }
           maxi=max(maxi,cnt);
           cnt=0;
        }
        return maxi<2?-1: maxi;
    }
};