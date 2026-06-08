// Last updated: 6/9/2026, 3:55:24 AM
1class Solution {
2public:
3    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
4        int playerMoves = abs(target[0]) + abs(target[1]);
5        int ghostMinMoves = 1e9;
6        for(auto &it : ghosts){
7            int dis = abs(it[0]-target[0]) + abs(it[1]-target[1]);
8            ghostMinMoves = min(dis,ghostMinMoves);
9        }
10        return playerMoves < ghostMinMoves;
11    }
12};