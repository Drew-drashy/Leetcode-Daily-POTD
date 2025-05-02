class Solution {
public:
    string pushDominoes(string str) {
        int n=str.size();
        vector<int>leftClosetR(n);
        vector<int>rightClosetL(n);
    
        for(int i=0;i<n;i++){
            // if(i==0){
                if(str[i]=='R'){
                    leftClosetR[i]=i;
                }
                else{
                    if(i==0 || str[i]=='L')leftClosetR[i]=-1;
                    
                    else leftClosetR[i]=leftClosetR[i-1];
                }
                
            // }
            // else{
            //     if(str[i]=='R'){
            //         leftClosetR[i]=0;
            //     }
            //     else{
                    
            //     }
            // }
        }
        for(int i=n-1;i>=0;i--){
            // if(i==0){
                if(str[i]=='L'){
                    rightClosetL[i]=i;
                }
                else{
                    if(i==n-1 || str[i]=='R')rightClosetL[i]=-1;
                    else rightClosetL[i]=rightClosetL[i+1];
                }
                
            
        }
        // for(auto it: rightClosetL ){
        //     cout<<it<<" ";
        // }
        // cout<<"\n";
        // for(auto it: leftClosetR ){
        //     cout<<it<<" ";
        // }
        for(int i=0;i<n;i++){
            if(leftClosetR[i]==-1 && rightClosetL[i]==-1) continue;
            else if(leftClosetR[i]==-1) {str[i]='L';continue;}
            else if(rightClosetL[i]==-1) {str[i]='R';continue;}
            int rdist=abs(i-leftClosetR[i]);
            int ldist=abs(i-rightClosetL[i]);
            if(rdist==ldist) continue;
            if(rdist>ldist) str[i]='L';
            else str[i]='R';

        }


        return str;
    }
};