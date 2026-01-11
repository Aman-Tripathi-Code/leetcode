// Last updated: 1/11/2026, 1:04:13 PM
class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        unordered_map <char,int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        for(int i =0;i<s.length()-1;i++){
            char ch1=s[i],ch2 = s[i+1];
            if(mp[ch1]<mp[ch2]){
                sum -= mp[s[i]];
            }
            else sum+= mp[s[i]];
        }
        sum+= mp[s[s.length()-1]];
        return sum;
    }
};