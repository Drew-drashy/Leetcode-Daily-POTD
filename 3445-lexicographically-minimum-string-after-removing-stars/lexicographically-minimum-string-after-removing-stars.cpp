class Solution {
public:
    struct compare{
        bool operator()(const pair<char,int>&a,const pair<char,int>&b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first>b.first;
        }
    };
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare>pq;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                pq.push({s[i],i});
            }
            else{
                int idx=pq.top().second;
                s[idx]='*';
                pq.pop();
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                ans+=s[i];
            }
        }
        return ans;
    }
};