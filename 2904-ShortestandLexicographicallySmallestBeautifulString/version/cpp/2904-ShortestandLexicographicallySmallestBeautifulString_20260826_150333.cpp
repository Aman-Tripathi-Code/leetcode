// Last updated: 8/26/2026, 3:03:33 PM
1class Solution {
2public:
3    void cmp(int &start, int i, int minLen, string s){
4        for(int x = 0; x < minLen; x++){
5            if(s[i + x] < s[start + x]){
6                start = i;
7                return;
8            }
9            if(s[i + x] > s[start + x]){
10                return;
11            }
12        }
13    }
14    string shortestBeautifulSubstring(string s, int k) {
15        int n = s.size();
16        int minLen = INT_MAX, start = -1;
17        int i = 0, j = 0, curr = 0;
18        while (j < n) {
19            curr += (s[j] - '0');
20            if (curr == k) {
21                while (curr == k) {
22                    if (minLen > (j - i + 1)) {
23                        minLen = (j - i + 1);
24                        start = i;
25                    } 
26                    else if (minLen == (j - i + 1)) {
27                        cmp(start,i,minLen,s);
28                    }
29                    curr -= (s[i]-'0');
30                    i++;
31                }
32            }
33            j++;
34        }
35        if(start == -1) return "";
36        return s.substr(start,minLen);
37    }
38};