class Solution {
public:
    long long fun(string &str,string &temp,int limit){
        if(str.length()<temp.length()){
            return 0;
        }
        long long count=0;
        string trailString=str.substr(str.length()- temp.length());
        int remainL=str.length()-temp.length();
        for(int i=0;i<remainL;i++){
            int digit=str[i]-'0';

            if(digit<=limit){
                count+=digit*pow(limit+1,remainL-i-1);
            }
            else{
                count+=pow(limit+1,remainL-i);
                return count;
            }

        }
        if(trailString>=temp) return count+1;
        return count;
    }
    
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string ans=to_string(start-1);
        string bns=to_string(finish);
        return fun(bns,s,limit)-fun(ans,s,limit);
    }
};