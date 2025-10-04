class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int n=height.size();
        int r=n-1;
        int ans=0;
        while(l<r){
            int val=(r-l)*min(height[r],height[l]);
            ans=max(ans,val);
            if(height[l]>height[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};