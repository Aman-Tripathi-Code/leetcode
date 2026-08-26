// Last updated: 8/26/2026, 2:56:09 PM
1class Solution {
2public:
3    void cmp(int &start, int &end, int i, int j, string s){
4        string s1 = s.substr(start,end-start+1), s2 = s.substr(i,j-i+1);
5        if(s2 < s1){
6            start = i;
7            end = j;
8        }
9    }
10    string shortestBeautifulSubstring(string s, int k) {
11        int n = s.size();
12        int minLen = INT_MAX, start = -1, end = -1;
13        int i = 0, j = 0, curr = 0;
14        while (j < n) {
15            curr += (s[j] - '0');
16            if (curr == k) {
17                while (curr == k) {
18                    if (minLen > (j - i + 1)) {
19                        minLen = (j - i + 1);
20                        start = i;
21                        end = j;
22                    } 
23                    else if (minLen == (j - i + 1)) {
24                        cmp(start, end, i, j,s);
25                    }
26                    curr -= (s[i]-'0');
27                    i++;
28                }
29            }
30            j++;
31        }
32        if(start == -1) return "";
33        return s.substr(start,end-start+1);
34    }
35};