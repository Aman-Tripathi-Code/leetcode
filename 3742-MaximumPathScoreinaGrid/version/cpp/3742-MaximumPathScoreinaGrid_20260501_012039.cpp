// Last updated: 5/1/2026, 1:20:39 AM
1class Solution {
2public:
3    int maxPathScore(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MIN)));
7        dp[0][0][0] = 0;
8        for (int i = 0; i < m; i++) {
9            for (int j = 0; j < n; j++) {
10                for (int c = 0; c <= k; c++) {
11                    if (dp[i][j][c] == INT_MIN) continue;
12                    if (i + 1 < m) {
13                        int val = grid[i + 1][j];
14                        int cost = (val == 0 ? 0 : 1);
15                        if (c + cost <= k) {
16                            dp[i + 1][j][c + cost] =
17                                max(dp[i + 1][j][c + cost], dp[i][j][c] + val);
18                        }
19                    }
20                    if (j + 1 < n) {
21                        int val = grid[i][j + 1];
22                        int cost = (val == 0 ? 0 : 1);
23                        if (c + cost <= k) {
24                            dp[i][j + 1][c + cost] =
25                                max(dp[i][j + 1][c + cost], dp[i][j][c] + val);
26                        }
27                    }
28                }
29            }
30        }
31        int ans = INT_MIN;
32        for (int c = 0; c <= k; c++) {
33            ans = max(ans, dp[m - 1][n - 1][c]);
34        }
35        return ans < 0 ? -1 : ans;
36    }
37};