// Last updated: 6/16/2026, 2:12:11 AM
1class Solution {
2public:
3    string processStr(string s) {
4        string ans;
5        int n = s.length();
6        for(int i = 0; i<n; i++){
7            if(s[i] >= 'a' && s[i] <= 'z'){
8                ans.push_back(s[i]);
9            }else if(s[i] == '*'){
10                if(ans.length() > 0) ans.erase(ans.size()-1,1);
11            }else if(s[i] == '#'){
12                ans = ans + ans;
13            }else{
14                reverse(ans.begin(),ans.end());
15            }
16        }
17        return ans;
18    }
19};