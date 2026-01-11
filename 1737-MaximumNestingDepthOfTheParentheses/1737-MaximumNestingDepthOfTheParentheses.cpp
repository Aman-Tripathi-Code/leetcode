// Last updated: 1/11/2026, 1:00:04 PM
class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int count = 0;
        for(auto it:s){
            if(it == '('){
                count++;
                res = max(res,count);
            }
            else if(it == ')'){
                count--;
            }
        }
        return res;
    }
};