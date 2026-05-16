// Last updated: 5/16/2026, 1:59:37 PM
1vector<vector<int>> graph;
2vector<int> vis;
3class Solution {
4public:
5    bool dfs(int node) {
6        vis[node] = 2;
7        for (auto& it : graph[node]) {
8            if (vis[it] == 1) {
9                if (dfs(it)) {
10                    return true;
11                }
12            } else if (vis[it] == 2) {
13                return true;
14            } else {
15                continue;
16            }
17        }
18        vis[node] = 3;
19        return false;
20    }
21
22    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
23        graph.assign(numCourses, vector<int>());
24        vis.assign(numCourses, 1);
25
26        for (auto& it : prereq) {
27            int u = it[0], v = it[1];
28            graph[v].push_back(u);
29        }
30
31        for (int i = 0; i < numCourses; i++) {
32            if (vis[i] == 1) {
33                if (dfs(i)) {
34                    return false;
35                }
36            }
37        }
38        return true;
39    }
40};