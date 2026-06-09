// Last updated: 6/9/2026, 11:10:13 PM
1class Solution {
2public:
3    bool isVowel(char ch) {
4        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
5    }
6    int beautifulSubstrings(string s, int k) {
7        int cnt = 0, n = s.size();
8        for (int i = 0; i < n; i++) {
9            int vowel = 0, cons = 0;
10            for (int j = i; j < n; j++) {
11                if (isVowel(s[j])) vowel++; 
12                else cons++;
13                if((vowel == cons) && ((vowel * cons)%k == 0)) cnt++;
14            }
15        }
16        return cnt;
17    }
18};