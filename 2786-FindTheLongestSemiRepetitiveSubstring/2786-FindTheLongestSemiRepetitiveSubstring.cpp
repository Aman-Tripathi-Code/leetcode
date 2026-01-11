// Last updated: 1/11/2026, 12:59:33 PM
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int i = 0, j = 1, n = s.size();
        int maxi = 1, count = 0;
        while(j < n){
            if(s[j] == s[j-1]){
                count++;
            }
            if(count < 2){
                maxi = max(maxi,j-i+1);
            }
            else if(count == 2){
                while(true){
                    if(s[i]==s[i+1]){
                        count--;
                        break;
                    }
                    i++;
                }
                i++;
                maxi = max(maxi,j-i+1);
            }
            j++;
        }
        return maxi;
    }
};