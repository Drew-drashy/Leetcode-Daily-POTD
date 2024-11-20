class Solution {
public:
    int takeCharacters(string s, int k) {
       int n=s.size();
       int cnt[3]={0};
       for(char i: s){
        cnt[i-'a']++;
       }
       if(min({cnt[0],cnt[1],cnt[2]})<k) return -1;
       int res=n;
       int j=0;
       for(int i=0;i<n;i++){
        while(j<n && cnt[s[j]-'a']>k){
            cnt[s[j++]-'a']--;

        }
        res=min(res,i+n-j);
        cnt[s[i]-'a']++;
       }
       return res;

    }
};

// class Solution {
// public:
//     int takeCharacters(string s, int k) {
//         int n = s.size(), cnt[3] = {};

//         for (char c : s) {
            
//             cnt[c-'a']++;
//         }
//         if (min({cnt[0], cnt[1], cnt[2]}) < k) return -1;

//         int res = n;
//         for (int i = 0, j = 0; i < n; i++) {
//             while (j < n && cnt[s[j]-'a'] > k)
//                 cnt[s[j++]-'a']--;
//             res = min(res, i + (n - j));
//             cnt[s[i]-'a']++;
//         }

//         return res;
//     }
// };