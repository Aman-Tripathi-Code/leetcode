// Last updated: 5/12/2026, 10:39:37 PM
1class Solution {
2public:
3    int findJudge(int n, vector<vector<int>>& trust) {
4        int ans = -1, cnt = 0;
5        if (n == 1)
6            return 1;
7        vector<int> deg(n + 1, 0);
8        for (auto& it : trust) {
9            deg[it[0]]--;
10            deg[it[1]]++;
11        }
12        for (int i = 1; i <= n; i++) {
13            if (deg[i] >= n - 1) {
14                ans = i;
15                cnt++;
16            }
17            if(cnt > 1) return -1;
18        }
19        return ans;
20    }
21};