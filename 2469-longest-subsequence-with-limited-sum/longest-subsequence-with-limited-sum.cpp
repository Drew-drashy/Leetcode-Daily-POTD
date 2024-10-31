class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        vector<int>res;
        for(int q: queries){
            int cnt=0;
            int sum=0;
            for(int i=0;i<nums.size();i++){
                if(sum+nums[i]<=q){
                    sum+=nums[i];
                    cnt++;
                }
                else{
                    break;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};