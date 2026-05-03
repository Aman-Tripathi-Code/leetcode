// Last updated: 5/3/2026, 3:20:33 PM
1class Solution {
2public:
3    bool isNonAlphaNum(char ch) {
4        return !((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
5    }
6    bool isPalindrome(string s) {
7        int i = 0, j = s.size() - 1;
8        while (i <= j) {
9            if (isNonAlphaNum(s[i])) {
10                i++;
11                continue;
12            }
13            if (isNonAlphaNum(s[j])) {
14                j--;
15                continue;
16            }
17            char ch1 = tolower(s[i]), ch2 = tolower(s[j]);
18            if (ch1 != ch2) {
19                return false;
20            } else {
21                i++;
22                j--;
23            }
24        }
25        return true;
26    }
27};