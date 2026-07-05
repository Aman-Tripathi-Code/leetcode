// Last updated: 7/6/2026, 1:58:08 AM
1using PII = pair<int, int>;
2
3class Solution {
4private:
5    static constexpr int mod = (int)1e9 + 7;
6
7public:
8    void update(vector<vector<PII>>& dp, int n, int x, int y, int u, int v) {
9        if (u >= n || v >= n || dp[u][v].first == -1) {
10            return;
11        }
12        if (dp[u][v].first > dp[x][y].first) {
13            dp[x][y] = dp[u][v];
14        } else if (dp[u][v].first == dp[x][y].first) {
15            dp[x][y].second += dp[u][v].second;
16            if (dp[x][y].second >= mod) {
17                dp[x][y].second -= mod;
18            }
19        }
20    }
21
22    vector<int> pathsWithMaxScore(vector<string>& board) {
23        int n = board.size();
24        vector<vector<PII>> dp(n, vector<PII>(n, {-1, 0}));
25        dp[n - 1][n - 1] = {0, 1};
26        for (int i = n - 1; i >= 0; --i) {
27            for (int j = n - 1; j >= 0; --j) {
28                if (!(i == n - 1 && j == n - 1) && board[i][j] != 'X') {
29                    update(dp, n, i, j, i + 1, j);
30                    update(dp, n, i, j, i, j + 1);
31                    update(dp, n, i, j, i + 1, j + 1);
32                    if (dp[i][j].first != -1) {
33                        dp[i][j].first +=
34                            (board[i][j] == 'E' ? 0 : board[i][j] - '0');
35                    }
36                }
37            }
38        }
39        return dp[0][0].first == -1
40                   ? vector<int>{0, 0}
41                   : vector<int>{dp[0][0].first, dp[0][0].second};
42    }
43};