class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n=boxes.size();
        vector<int>ans(n,0);
        vector<int>left(n,0);
        vector<int>right(n,0);
        int ind=0;
        for(int i=0;i<n-1;i++){
            int cnt=0;
            for(int j=i+1;j<n;j++){
                if(boxes[j]=='1'){
                    cnt+=abs(i-j);
                }
            }
            left[ind++]=cnt;
        }
        // cout<<"hi";
        ind=n-1;
        for(int i=n-1;i>=1;i--){
            // cout<<"hi";
            int cnt=0;
            for(int j=i-1;j>=0;j--){
                if(boxes[j]=='1'){
                    cnt+=abs(j-i);
                }
            }
            right[ind--]=cnt;
        }

        for(int i=0;i<n;i++){
            ans[i]=left[i]+right[i];
        }
        return ans;
    }
};