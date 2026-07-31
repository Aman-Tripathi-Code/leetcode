// Last updated: 7/31/2026, 3:10:40 PM
1class Solution {
2public:
3    int minimumPushes(string word) {
4        int hs[26];
5        memset(hs,0,sizeof(hs));
6        for(char ch : word){
7            hs[ch-'a']++;
8        }
9        sort(hs,hs+26,greater<int>());
10        int res = 0;
11        for(int i = 0; i<26; i++){
12            if(hs[i] == 0) break;
13            res += ((i / 8) + 1) * hs[i];
14        }
15        return res;
16    }
17};