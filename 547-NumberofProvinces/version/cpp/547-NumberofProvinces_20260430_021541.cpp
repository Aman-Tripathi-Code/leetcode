// Last updated: 4/30/2026, 2:15:41 AM
1class Solution {
2public:
3    void dfs(int node , vector<int>&vis, vector<vector<int>> &graph){
4        vis[node] = 1;
5
6        for(int v : graph[node]){
7            if(!vis[v]){
8                dfs(v,vis,graph);
9            }
10        }
11    }
12
13
14    int findCircleNum(vector<vector<int>>& isConnected) {
15        int n = isConnected.size(), m = isConnected[0].size();
16        vector<vector<int>> graph(n);
17        for(int i = 0; i<n; i++){
18            for(int j = i+1; j<m; j++){
19                if(isConnected[i][j]){
20                    graph[i].push_back(j);
21                    graph[j].push_back(i);
22                }
23            }
24        }
25
26        vector<int> vis(n,0);
27        int numOfProvince = 0;
28
29        for(int i = 0; i<n; i++){
30            if(!vis[i]){
31                dfs(i,vis,graph);
32                numOfProvince++;
33            }
34        }
35
36        return numOfProvince;
37
38    }
39};