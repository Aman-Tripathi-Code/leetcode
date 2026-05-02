// Last updated: 5/2/2026, 7:29:17 PM
1int dp[10][2][10];
2string s;
3class Solution {
4public:
5    int solve(int pos, bool tight, int oneCnt){
6        if(pos == s.size()){
7            return oneCnt;
8        }
9        if(dp[pos][tight][oneCnt] != -1){
10            return dp[pos][tight][oneCnt];
11        }
12
13        int limit = (tight) ? (s[pos] - '0') : 9;
14        int res = 0;
15        for(int d = 0; d <= limit; d++){
16            int newTight = tight && (d == limit);
17            int newOneCnt = oneCnt + (d == 1);
18            res += solve(pos+1, newTight, newOneCnt);
19        }
20
21        return dp[pos][tight][oneCnt] = res;
22    }
23    int countDigitOne(int n) {
24        s = to_string(n);
25        memset(dp,-1,sizeof(dp));
26        return solve(0,1,0);
27    }
28};