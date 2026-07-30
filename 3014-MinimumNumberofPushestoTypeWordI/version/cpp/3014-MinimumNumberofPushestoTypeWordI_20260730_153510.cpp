// Last updated: 7/30/2026, 3:35:10 PM
1class Solution {
2public:
3    int minimumPushes(string word) {
4        int hs[26];
5        memset(hs,0,sizeof(hs));
6        for(char ch : word){
7            hs[ch-'a']++;
8        }
9        sort(hs,hs+26,greater<int>());
10        int res = 0, cnt = 0;
11        for(int i = 0; i<26; i++){
12            if(hs[i] == 0) break;
13            if(i % 8 == 0){
14                cnt++;
15            }
16            res += cnt * hs[i];
17        }
18        return res;
19    }
20};