class Solution {
public:
    string answerString(string word, int numFriends) {
        char d='A';
        for(auto i:word){
            if(d<i){
                d=i;
            }
        }
        if(numFriends==1){
            return word;  //edge case
        }
        priority_queue<pair<char,int>> pq;
        for(int i=0;i<word.size();i++){
            if(word[i]==d){
                pq.push({d,i});
            }
        }
        string sol="";
        while(!pq.empty()){
            pair<char,int> p=pq.top();
            pq.pop();
            int k;
            int prev=p.second;
            int help=numFriends-prev-1;
            if(prev>=numFriends-1){ //partition all other alphabet in a string of single length
                help=0;
            }
                string solution="";
                for(k=p.second;k<word.size()-help;k++){
                    solution+=word[k];
                }
                if(sol<solution){
                    sol=solution;
                }
            
            
        }
        return sol;
    }
};