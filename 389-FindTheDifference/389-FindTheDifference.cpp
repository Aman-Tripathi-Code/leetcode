// Last updated: 1/11/2026, 1:01:55 PM
class Solution {
public:
    char findTheDifference(string s, string t) {
        int hs[26];
        memset(hs,0,sizeof(hs));
        char ch;
        for(int i = 0; i<s.size(); i++){
            hs[s[i]-'a']++;
        }
        for(int i = 0; i<t.size(); i++){
            if(hs[t[i]-'a']==0){
                ch = t[i];
                break;
            }
            hs[t[i]-'a']--;
        }
        return ch;
    }
};