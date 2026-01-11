// Last updated: 1/11/2026, 1:03:02 PM
class Solution {
public:
    bool isPali(string s){
        int ind = 0; int sz = s.size();
        while(ind < sz/2){
            if(s[ind]!=s[sz-1-ind]){
                return false;
            }
            ind++;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string q;
        int sz = s.size();
        for(int i = 0; i<sz; i++){
            if(s[i]>='A'&&s[i]<='Z'){
                s[i] += 32;
            }
        }
        for(int i = 0; i<sz; i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
                q.push_back(s[i]);
            }
        }
        return isPali(q);
    }
};