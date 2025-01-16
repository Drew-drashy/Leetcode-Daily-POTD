class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n%2==0 && m%2==0) return 0;
        int x1=0;
        int x2=0;
        for(int i: nums1) x1^=i;
        for(int i: nums2) x2^=i;
        if(n%2 && m%2==0){
            return x2;
        }
        else if (n%2!=0 && m%2!=0) return x1^x2;
        return x1;

    }
};