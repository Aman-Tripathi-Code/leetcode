// Last updated: 6/11/2026, 11:14:27 PM
1class Solution {
2public:
3    int mod = 1e9+7;
4    int dfs(int node, vector<int>&vis, vector<vector<int>>& graph){
5        vis[node] = 1;
6        int maxDepth = 0;
7        for(auto &it: graph[node]){
8            if(!vis[it]){
9                maxDepth = max(maxDepth,dfs(it,vis,graph));
10            }
11        }
12        return 1 + maxDepth;
13    }
14    int binPow(int a, int b){
15        long long res = 1;
16        while(b){
17            if(b & 1){
18                res = (res * a * 1LL)%mod;
19            }
20            a = (a * 1LL * a)%mod;
21            b >>= 1;
22        }
23        return res%mod;
24    }
25    int assignEdgeWeights(vector<vector<int>>& edges) {
26        int n = edges.size() + 1;
27        vector<vector<int>> graph(n+1);
28        for(auto &it: edges){
29            int u = it[0], v = it[1];
30            graph[u].push_back(v);
31            graph[v].push_back(u);
32        }
33        vector<int> vis(n+1,0);
34        int depth = dfs(1,vis,graph) - 1;
35        return binPow(2,depth-1);
36    }
37};