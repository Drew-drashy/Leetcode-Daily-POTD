class Solution {
public:
    void fun(long long int val,int n,vector<int>&res){
        if(val>n) return;
        res.push_back(val);
        for(int i=0;i<=9;i++){
            long long int temp=val*10+i;
            fun(temp,n,res);
        }
    }
    vector<int> lexicalOrder(int n) {
       
        vector<int>res;
        for(int i=1;i<=9;i++){
            fun(i,n,res);
        }
        return res;

    }
};