// class Solution {
// public:
//     int largestCombination(vector<int>& candidates) {
//         vector<int>dp(24,0);
//         for(int i: candidates){
//             for(int j=0;j<24;j++){
//                 if(i&1<<j) dp[j]++;
//             }
//         }
//         int maxi=0;
//         for(int i=0;i<24;i++) maxi=max(maxi,dp[i]);
//         return maxi;
//     }
// };
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("O3", "unroll-loops")
#pragma GCC optimize ("-ffloat-store")

auto init = []() { 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
} ();

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        std::array<int, 24> bc{};

        for(int i : candidates) {
            int sh{0};
            while(i) {
                bc[sh] += i & 1;
                ++sh;
                i >>= 1;
            }
        }

        return *std::max_element(bc.cbegin(), bc.cend());
    }
};

