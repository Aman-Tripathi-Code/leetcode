// Last updated: 1/11/2026, 1:02:09 PM
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v1(26);
        for(int i = 0; i<s.length() ; i++){
            v1[s[i]-'a']++;
        }
        
        vector<int> v2(26);
        for(int i = 0; i<t.length() ; i++){
            v2[t[i]-'a']++;
        }
        int count = 0;
        for(int i = 0 ; i<26 ; i++){
            if(v1[i]!=v2[i]){
                count++;
            }
        }
        if(count){
            return false;
        }
        return true;
    }
};