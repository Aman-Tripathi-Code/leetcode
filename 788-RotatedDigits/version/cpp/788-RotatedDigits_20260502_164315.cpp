// Last updated: 5/2/2026, 4:43:15 PM
1string s;
2int dp[5][2][2];
3
4class Solution {
5public:
6    int solve(int pos, bool tight, bool hasGoodNo){
7        if(pos == s.size()){
8            return hasGoodNo;
9        }
10
11        if(dp[pos][tight][hasGoodNo] != -1){
12            return dp[pos][tight][hasGoodNo];
13        }
14
15        int limit = (tight) ? (s[pos] - '0') : 9;
16        int res = 0;
17
18        for(int d = 0; d <= limit; d++){
19            bool newTight = tight && (d == limit);
20            bool newHasGoodNo = hasGoodNo || (d == 2 || d == 5 || d == 6 || d == 9);
21            if(d == 3 || d == 4 || d == 7) continue;
22            res += solve(pos+1,newTight,newHasGoodNo);
23        }
24
25        return dp[pos][tight][hasGoodNo] = res;
26
27    }
28    int rotatedDigits(int n) {
29        s = to_string(n);
30        memset(dp,-1,sizeof(dp));
31        return solve(0,1,0); 
32    }
33};