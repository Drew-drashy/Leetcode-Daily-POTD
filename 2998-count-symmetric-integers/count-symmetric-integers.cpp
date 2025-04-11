class Solution {
public:
    bool fun(int val){
        string nums=to_string(val);
        if(nums.size()<2 || nums.size()%2) return false;
        int right=0,left=0;
        for(int i=0;i<nums.size()/2;i++){
            left+=nums[i]-'0';
        }
        for(int i=nums.size()/2;i<nums.size();i++){
            right+=nums[i]-'0';
        }
        return left==right;



    }
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            if(fun(i)) cnt++;
        }
        return cnt;
    }
};