// Last updated: 1/11/2026, 1:00:41 PM
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int count = 0;
        for(auto it:s){
            if(it == '('){
                if(count > 0) res += '(';
                count++;
            }
            else{
                count--;
                if(count > 0) res += ')';
            }
        }
        return res;
    }
};