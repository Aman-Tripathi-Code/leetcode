// Last updated: 1/11/2026, 1:02:47 PM
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string temp;
        vector<string> words;
        while(ss >> temp){
            words.push_back(temp);
        }
        string ans;
        for(int i = words.size()-1; i>=0 ; i--){
            if(i != words.size()-1){
                ans += " ";
            }
            ans += words[i];
        }
        return ans;
    }
};