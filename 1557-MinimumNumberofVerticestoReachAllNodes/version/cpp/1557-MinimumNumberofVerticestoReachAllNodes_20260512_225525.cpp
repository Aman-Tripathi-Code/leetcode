// Last updated: 5/12/2026, 10:55:25 PM
1class Solution {
2public:
3    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
4        vector<int> indegree(n,0);
5        for(auto &edge: edges){
6            int u = edge[0], v = edge[1];
7            indegree[v]++;
8        }
9        vector<int> ans;
10        for(int i = 0; i<n; i++){
11            if(indegree[i] == 0) ans.push_back(i);
12        }
13        return ans;
14    }
15};