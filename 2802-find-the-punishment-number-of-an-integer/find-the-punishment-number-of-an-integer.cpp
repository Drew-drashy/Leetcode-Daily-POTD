class Solution {
private:
    unordered_map<string,unordered_map<int,bool>>mp;
    bool conditions(string number, int value){
        if(mp.find(number) != mp.end()){
            if(mp[number].find(value) != mp[number].end()){
                return mp[number][value];
            }
        }
        if(number == "") return (value == 0) ? true : false;
        
        int n = number.length();
        bool key = false;
        for(int i = 1 ; i <= n ; i++){
            key |= conditions(number.substr(i,n-i),value - stoi(number.substr(0,i)));
        }
        return mp[number][value] = key;
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            if(conditions(to_string(i*i),i)){
                ans += i * i ;
            }
        }
        return ans;
    }
};