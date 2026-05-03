// Last updated: 5/3/2026, 10:26:18 AM
1class Solution {
2private:
3    bool isCycle(int node, vector<int> &vis, vector<int> &dfsVis, vector<vector<int>> &adj){
4        vis[node] = 1;
5        dfsVis[node] = 1;
6        for(auto it:adj[node]){
7            if(!vis[it]){
8                if(isCycle(it,vis,dfsVis,adj)){
9                    return true;
10                }
11            }
12            else if(dfsVis[it] == 1){
13                return true;
14            }
15        }
16        dfsVis[node] = 0;
17        return false;
18    }
19public:
20    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
21        vector<int> vis(numCourses);
22        vector<int> dfsVis(numCourses);
23
24        vector<vector<int>> adj(numCourses);
25
26        for(auto it:prerequisites){
27            adj[it[1]].push_back(it[0]);
28        }
29
30        for(int i = 0; i<numCourses; i++){
31            if(vis[i] == 0){
32                if(isCycle(i,vis,dfsVis,adj)){
33                    return false;
34                }
35            }
36        }
37        return true;
38    }
39};