// Last updated: 8/5/2026, 11:15:58 PM
1class Solution {
2public:
3    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
4        vis[node] = 1;
5        for (auto& it : adj[node]) {
6            if (!vis[it]) {
7                dfs(it, vis, adj);
8            }
9        }
10    }
11    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
12        vector<vector<int>> adj(n);
13        for (auto& node : inv) {
14            int u = node[0], v = node[1];
15            adj[u].push_back(v);
16        }
17        vector<int> vis(n, 0);
18        dfs(k, vis, adj);
19        vector<int> newVis(n, 0);
20        for (int i = 0; i < n; i++) {
21            if (!vis[i] && !newVis[i]) {
22                dfs(i, newVis, adj);
23            }
24        }
25        bool flag = false;
26        for (int i = 0; i < n; i++) {
27            if (vis[i] == 1 && newVis[i] == 1) {
28                flag = true;
29                break;
30            }
31        }
32        vector<int> ans;
33        for (int i = 0; i < n; i++) {
34            if (vis[i] && !flag) {
35                continue;
36            }
37            ans.push_back(i);
38        }
39        return ans;
40    }
41};