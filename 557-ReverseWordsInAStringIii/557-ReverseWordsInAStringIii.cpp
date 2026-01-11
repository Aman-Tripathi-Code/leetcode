// Last updated: 1/11/2026, 1:01:31 PM
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int j = 0;
        for(int i = 0; i<n; i++){
            if(s[i] != ' '){
                continue;
            }
            else{
                reverse(s.begin()+j,s.begin()+i);
                j = i+1;
            }
        }
        if(s[n-1] != ' '){
            reverse(s.begin()+j,s.end());
        }
        return s;
    }
};