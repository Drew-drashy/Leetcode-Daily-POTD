class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()>2){
                while(mp.size()>2){ 
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0) mp.erase(fruits[i]);
                    i++;
                    
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};

//  1 2 1
//  b1 b2

// 2 ,1 
// maxi =2,

//  0 1 2 2 (3)
   
//    1 2 3 2 2 

//    max of fruits and 
//    second max.
