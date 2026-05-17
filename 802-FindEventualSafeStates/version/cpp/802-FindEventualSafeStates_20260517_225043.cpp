// Last updated: 5/17/2026, 10:50:43 PM
1class Solution {
2public:
3    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
4        int n = graph.size();
5        vector<vector<int>> rev(n);
6        vector<int> indeg(n,0);
7        for(int i = 0; i<n; i++){
8            for(auto &it: graph[i]){
9                rev[it].push_back(i);
10                indeg[i]++;
11            }
12        }
13        queue<int> q;
14        for(int i = 0; i<n; i++){
15            if(indeg[i] == 0){
16                q.push(i);
17            }
18        }
19        vector<int> ans;
20        while(!q.empty()){
21            int node = q.front();
22            q.pop();
23            ans.push_back(node);
24
25            for(auto &it: rev[node]){
26                indeg[it]--;
27                if(indeg[it] == 0){
28                    q.push(it);
29                }
30            }
31        }
32        sort(ans.begin(),ans.end());
33        return ans;
34    }
35};