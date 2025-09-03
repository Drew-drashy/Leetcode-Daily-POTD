class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int> &b){
        return (a[0]==b[0]) ? a[1]>b[1] : a[0]<b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        sort(points.begin(),points.end(),cmp);
        for(int i=0;i<points.size()-1;i++){
            int y=INT_MIN;
            int yi=points[i][1];
            for(int j=i+1;j<n;j++){
                int yj=points[j][1];
                if(yj<=yi && yj>y){
                    ans++;
                    y=yj;
                }
            }
        }
        return ans;
        
    }
};