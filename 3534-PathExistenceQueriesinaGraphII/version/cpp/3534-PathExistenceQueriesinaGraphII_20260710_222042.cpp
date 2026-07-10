// Last updated: 7/10/2026, 10:20:42 PM
1class Solution {
2public:
3    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
4                                     vector<vector<int>>& queries) {
5        vector<int> idx(n), pos(n), res;
6        iota(idx.begin(), idx.end(), 0);
7        sort(idx.begin(), idx.end(),
8             [&](int a, int b) { return nums[a] < nums[b]; });
9        for (int i = 0; i < n; i++) {
10            pos[idx[i]] = i;
11        }
12
13        int m = 32 - __builtin_clz(n);
14        vector<vector<int>> f(n, vector<int>(m));
15
16        for (int i = 0, left = 0; i < n; i++) {
17            while (nums[idx[i]] - nums[idx[left]] > maxDiff) left++;
18            f[i][0] = left;
19        }
20
21        for (int j = 1; j < m; j++) {
22            for (int i = 0; i < n; i++) {
23                f[i][j] = f[f[i][j - 1]][j - 1];
24            }
25        }
26
27        for (auto& q : queries) {
28            auto [x, y] = pair(pos[q[0]], pos[q[1]]);
29            if (x > y) {
30                swap(x, y);
31            }
32            if (x == y) {
33                res.push_back(0);
34                continue;
35            }
36
37            int step = 0;
38            for (int i = m - 1; i >= 0; i--) {
39                if (f[y][i] > x) {
40                    y = f[y][i];
41                    step += 1 << i;
42                }
43            }
44
45            res.push_back(f[y][0] <= x ? step + 1 : -1);
46        }
47        return res;
48    }
49};