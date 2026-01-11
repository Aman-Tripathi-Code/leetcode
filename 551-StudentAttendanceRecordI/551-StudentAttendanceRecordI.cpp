// Last updated: 1/11/2026, 1:01:32 PM
class Solution {
public:
    bool checkRecord(string s) {
        int l = s.length();
        int count = 0;
        for(int i = 0; i< l ; i++){
        if(s[i]=='A'){
            count++;
        }
        if(s[i]==s[i+1]&&s[i+1]==s[i+2]&&s[i]=='L'){
            return false;
        }
        }
        if(count>=2){
            return false;
        }
        return true;        
    }
};