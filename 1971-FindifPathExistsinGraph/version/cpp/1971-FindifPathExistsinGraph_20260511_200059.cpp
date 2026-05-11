// Last updated: 5/11/2026, 8:00:59 PM
1class Solution {
2public:
3    void dfs(int node, int dest, vector<bool>& vis, vector<vector<int>>& graph){
4        vis[node] = true;
5        if(node == dest){
6            return;
7        }
8        for(auto &it: graph[node]){
9            if(!vis[it]){
10                dfs(it,dest,vis,graph);
11            }
12        }
13    }
14
15    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
16        vector<vector<int>> graph(n);
17
18        for(auto &it: edges){
19            int u = it[0], v = it[1];
20            graph[u].push_back(v);
21            graph[v].push_back(u);
22        }
23
24        vector<bool> vis(n,false);
25        dfs(source,destination,vis,graph);
26        return vis[destination];
27    }
28};