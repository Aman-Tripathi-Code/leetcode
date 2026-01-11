// Last updated: 1/11/2026, 12:59:56 PM
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int ind = -1;
        for(int i = n-1; i>=0; i--){
            if((num[i] - '0') & 1){
                ind = i;
                break;
            }
        }
        return (ind == -1) ? "" : num.substr(0,ind+1);
    }
};