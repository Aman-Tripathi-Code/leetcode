// Last updated: 5/17/2026, 9:37:49 PM
1class Solution {
2public:
3    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
4        vector<vector<int>> graph(numCourses);
5        vector<int> indegree(numCourses,0);
6        for(auto &it: prerequisites){
7            int v = it[0], u = it[1];
8            graph[u].push_back(v);
9            indegree[v]++;
10        }
11        queue<int> q;
12        for(int i = 0; i<numCourses; i++){
13            if(indegree[i] == 0){
14                q.push(i);
15            }
16        }
17
18        vector<int> topo;
19        while(!q.empty()){
20            int node = q.front();
21            q.pop();
22
23            topo.push_back(node);
24            for(auto &it: graph[node]){
25                indegree[it]--;
26                if(indegree[it] == 0){
27                    q.push(it);
28                }
29            }    
30        }
31
32        if(topo.size() != numCourses){
33            return {};
34        }
35        return topo;
36
37
38    }
39};