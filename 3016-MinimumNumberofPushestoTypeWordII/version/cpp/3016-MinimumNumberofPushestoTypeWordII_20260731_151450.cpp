// Last updated: 7/31/2026, 3:14:50 PM
1class Solution {
2public:
3    int minimumPushes(string word) {
4        vector<int> hs(26,0);
5        for(char ch : word){
6            hs[ch-'a']++;
7        }
8        sort(hs.rbegin(),hs.rend());
9        int res = 0;
10        for(int i = 0; i<26; i++){
11            if(hs[i] == 0) break;
12            res += ((i / 8) + 1) * hs[i];
13        }
14        return res;
15    }
16};