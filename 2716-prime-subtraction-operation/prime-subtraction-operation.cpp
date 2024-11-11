class Solution {
public:
    bool prime[1000];
    void fun(){
        memset(prime,true,sizeof(prime));
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i*i<1000;i++){
            if(prime[i]){
                for(int j=i*i;j<1000;j+=i){
                    prime[j]=false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        fun();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]) continue;
            else{
                for(int p=2;p<nums[i];p++){
                    if(!prime[p]) continue;
                    else{
                        if(nums[i]-p<nums[i+1]){
                            nums[i]-=p;
                            break;
                        }
                    }
                }
            }
            if(nums[i]>=nums[i+1]) return false;
        }
        return true;
    }
};