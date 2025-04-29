class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int cnt=0;
        long long int len=0;
        int maxi=*max_element(nums.begin(),nums.end());
        while(j<n){
            
            if(maxi==nums[j]){
                cnt++;
            }
            if(cnt>=k){
                while(cnt>=k){
                    if(nums[i]==maxi){
                        cnt--;
                    }
                     i++;
                }
            }
            if(cnt<k){
                len+=j-i+1;
            }
            j++;
        }
        long long int N = static_cast<long long int>(n) * (n + 1) / 2;

        return N-len;

    }
};