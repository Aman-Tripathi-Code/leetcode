// Last updated: 4/2/2026, 12:31:27 AM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4       int n = s.size();
5       int i = 0, j = 0, maxi = 0;
6       vector<int> hs(256,0);
7       while(j < n){
8        hs[s[j]]++;
9        if(hs[s[j]] > 1){
10             while(hs[s[j]] > 1){
11                hs[s[i]]--;
12                i++;
13            }
14        }
15        maxi = max(maxi, (j-i+1));
16        j++;
17       }
18       return maxi; 
19    }
20};