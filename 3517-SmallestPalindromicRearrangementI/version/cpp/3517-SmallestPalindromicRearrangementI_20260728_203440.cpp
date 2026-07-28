// Last updated: 7/28/2026, 8:34:40 PM
1class Solution {
2public:
3    string smallestPalindrome(string s) {
4        int n = s.size();
5        sort(s.begin(),s.begin()+n/2);
6        for(int i = 0; i<=n/2; i++){
7            s[n-i-1] = s[i];
8        }
9        return s;
10    }
11};