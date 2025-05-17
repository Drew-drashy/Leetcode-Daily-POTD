class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int c1=0,c2=0,c3=0;
        for(int i: nums){
            if(i==0) c1++;
            else if(i==1) c2++;
            else c3++;
        }
        int ind=0;
        while(c1-->0 && ind<n){nums[ind++]=0;}
        while(c2-->0 && ind<n){nums[ind++]=1;}
        while(c3-->0 && ind<n){nums[ind++]=2;}
    }
};