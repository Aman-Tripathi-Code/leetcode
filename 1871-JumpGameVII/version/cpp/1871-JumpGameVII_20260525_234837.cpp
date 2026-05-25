// Last updated: 5/25/2026, 11:48:37 PM
1class Solution {
2public:
3    bool canReach(string s, int minJump, int maxJump) {
4
5        int n = s.size();
6
7        vector<int> dp(n, 0);
8        vector<int> pref(n, 0);
9
10        dp[0] = 1;
11        pref[0] = 1;
12
13        for(int i = 1; i < n; i++) {
14
15            if(s[i] == '0') {
16
17                int l = max(0, i - maxJump);
18                int r = i - minJump;
19
20                if(r >= 0) {
21
22                    int reachable =
23                        pref[r] - (l ? pref[l - 1] : 0);
24
25                    if(reachable > 0)
26                        dp[i] = 1;
27                }
28            }
29
30            pref[i] = pref[i - 1] + dp[i];
31        }
32
33        return dp[n - 1];
34    }
35};