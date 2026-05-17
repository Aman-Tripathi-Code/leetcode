// Last updated: 5/17/2026, 12:44:20 PM
1class Solution {
2public:
3    vector<vector<int>> graph;
4    bool isValid(int ind, int n) { return ind >= 0 && ind < n; }
5    bool dfs(int ind, vector<int>& vis, vector<int>& arr) {
6        vis[ind] = 1;
7        if (arr[ind] == 0) {
8            return true;
9        }
10        for (auto& it : graph[ind]) {
11            if (!vis[it]) {
12                if (dfs(it, vis, arr)) {
13                    return true;
14                }
15            }
16        }
17        return false;
18    }
19    bool canReach(vector<int>& arr, int start) {
20        int n = arr.size();
21        graph.resize(n);
22        bool containsZero = false;
23        for (int i = 0; i < n; i++) {
24            int fwd = i + arr[i], bwd = i - arr[i];
25            if (isValid(fwd, n))
26                graph[i].push_back(fwd);
27            if (isValid(bwd, n))
28                graph[i].push_back(bwd);
29            if (arr[i] == 0) {
30                containsZero = true;
31            }
32        }
33        if (!containsZero)
34            return false;
35        vector<int> vis(n, 0);
36
37        return dfs(start, vis, arr);
38    }
39};