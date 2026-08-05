// Last updated: 8/6/2026, 12:25:16 AM
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
19        bool flag = false;
20        for(auto &node: inv){
21            int u = node[0], v = node[1];
22            if(vis[u] == 0 && vis[v] == 1){
23                flag = true;
24                break;
25            }
26        }
27        vector<int> ans;
28        for (int i = 0; i < n; i++) {
29            if (vis[i] && !flag) {
30                continue;
31            }
32            ans.push_back(i);
33        }
34        return ans;
35    }
36};