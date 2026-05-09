// Last updated: 5/9/2026, 8:48:12 PM
1class Solution {
2public:
3    int minFlips(string s) {
4        int n = s.size(), flip = 0;
5        int totalCount = count(s.begin(),s.end(),'0');
6        vector<int> zero(n, 0);
7        int ind = -1;
8        for (int i = 0; i < n; i++) {
9            if (s[i] == '1') {
10                if (ind == -1) {
11                    ind = i;
12                }else if(ind == 0){
13                    if(totalCount - zero[i-1]){
14                        flip++;
15                    }
16                    else ind = i;
17                }else {
18                    if (zero[i-1] >= 1) {
19                        flip++;
20                    }
21                    else ind = i;
22                }
23                if(i > 0)zero[i] = zero[i - 1];
24            } else {
25                if (i == 0) {
26                    zero[i] = 1;
27                    continue;
28                } else {
29                    zero[i] = zero[i - 1] + 1;
30                }
31            }
32        }
33        if(totalCount < flip) flip = totalCount;
34        return flip;
35    }
36};