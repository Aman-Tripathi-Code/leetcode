// Last updated: 6/20/2026, 4:31:57 PM
1class Solution {
2public:
3    int maxBuilding(int n, vector<vector<int>>& restrictions) {
4        auto&& r = restrictions;
5        // Add restriction (1, 0)
6        r.push_back({1, 0});
7        sort(r.begin(), r.end());
8
9        // Add restriction (n, n-1)
10        if (r.back()[0] != n) {
11            r.push_back({n, n - 1});
12        }
13
14        int m = r.size();
15
16        // Pass restrictions from left to right
17        for (int i = 1; i < m; ++i) {
18            r[i][1] = min(r[i][1], r[i - 1][1] + (r[i][0] - r[i - 1][0]));
19        }
20        // Pass restrictions from right to left
21        for (int i = m - 2; i >= 0; --i) {
22            r[i][1] = min(r[i][1], r[i + 1][1] + (r[i + 1][0] - r[i][0]));
23        }
24
25        int ans = 0;
26        for (int i = 0; i < m - 1; ++i) {
27            // Calculate the maximum height of the buildings between r[i][0] and
28            // r[i][1]
29            int best = ((r[i + 1][0] - r[i][0]) + r[i][1] + r[i + 1][1]) / 2;
30            ans = max(ans, best);
31        }
32
33        return ans;
34    }
35};