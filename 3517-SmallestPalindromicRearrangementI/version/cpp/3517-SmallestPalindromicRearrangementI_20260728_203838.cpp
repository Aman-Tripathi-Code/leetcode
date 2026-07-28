// Last updated: 7/28/2026, 8:38:38 PM
1class Solution {
2public:
3
4    void countingSort(string &s,int n){
5        int hs[26];
6        memset(hs,0,sizeof(hs));
7
8        for(int i = 0; i<n/2; i++){
9            hs[s[i]-'a']++;
10        }
11        int ind = 0;
12        for(int i = 0; i<26; i++){
13            while(hs[i]){
14                s[ind++] = i + 'a';
15                hs[i]--;
16            }
17        }
18    }
19
20    string smallestPalindrome(string s) {
21        int n = s.size();
22        countingSort(s,n);
23        for(int i = 0; i<=n/2; i++){
24            s[n-i-1] = s[i];
25        }
26        return s;
27    }
28};