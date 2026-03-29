// Last updated: 3/29/2026, 11:54:13 AM
1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4        vector<int> hs(26,0);
5        int n = s.size(), m = t.size();
6        if(n != m) return false;
7        for(int i = 0; i<n; i++){
8            hs[t[i]-'a']++;
9            hs[s[i]-'a']--;
10        }
11        for(int i = 0; i<26; i++){
12            if(hs[i] != 0) return false;
13        }
14        return true;
15    }
16};