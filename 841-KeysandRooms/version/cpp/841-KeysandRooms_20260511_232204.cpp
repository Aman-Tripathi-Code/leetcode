// Last updated: 5/11/2026, 11:22:04 PM
1class Solution {
2public:
3    int dfs(int node, vector<int>&vis, vector<vector<int>>&rooms){
4        vis[node] = 1;
5        int cnt = 1;
6        for(auto &key: rooms[node]){
7            if(!vis[key]){
8                cnt += dfs(key,vis,rooms);
9            }
10        }
11        return cnt;
12    }
13
14    bool canVisitAllRooms(vector<vector<int>>& rooms) {
15        int n = rooms.size();
16        vector<int> vis(n,0);
17
18        return dfs(0,vis,rooms) == n;
19    }
20};