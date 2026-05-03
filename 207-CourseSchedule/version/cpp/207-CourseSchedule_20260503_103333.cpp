// Last updated: 5/3/2026, 10:33:33 AM
1vector<vector<int>> graph;
2vector<int> vis;
3class Solution {
4public:
5    bool dfs(int node) {
6        vis[node] = 2;
7        cout << node << endl;
8        for (auto& it : graph[node]) {
9            cout << it << ' ';
10            if (vis[it] == 1) {
11                if (dfs(it)) {
12                    return true;
13                }
14            } else if (vis[it] == 2) {
15                return true;
16            } else {
17                continue;
18            }
19        }
20        vis[node] = 3;
21        return false;
22    }
23
24    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
25        graph.assign(numCourses, vector<int>());
26        vis.assign(numCourses, 1);
27
28        for (auto& it : prereq) {
29            int u = it[0], v = it[1];
30            graph[v].push_back(u);
31        }
32
33        for (int i = 0; i < numCourses; i++) {
34            if (vis[i] == 1) {
35                if (dfs(i)) {
36                    return false;
37                }
38            }
39        }
40        return true;
41    }
42};