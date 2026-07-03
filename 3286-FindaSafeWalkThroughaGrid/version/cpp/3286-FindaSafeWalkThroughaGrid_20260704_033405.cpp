// Last updated: 7/4/2026, 3:34:05 AM
1using state = pair<int,int>;
2int dx[4] = {-1,0,1,0};
3int dy[4] = {0,1,0,-1};
4class Solution {
5public:
6    bool findSafeWalk(vector<vector<int>>& grid, int health) {
7        int n = grid.size(), m = grid.front().size();
8        deque<pair<int,state>> dq;
9        vector<vector<int>> dis(n,vector<int>(m,1e9));
10        if(grid[0][0] == 1){
11            dq.push_back(make_pair(1,make_pair(0,0)));
12            dis[0][0] = 1;
13        }else{
14            dq.push_front(make_pair(0,make_pair(0,0)));
15            dis[0][0] = 0;
16        }
17        while(!dq.empty()){
18            auto [dist, node] = dq.front();
19            auto [row,col] = node;
20            dq.pop_front();
21
22            for(int i = 0; i<4; i++){
23                int nrow = row + dx[i], ncol = col + dy[i];
24
25                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m){
26                    if(dis[nrow][ncol] > (dist + grid[nrow][ncol])){
27                        if(grid[nrow][ncol] == 1){
28                            dis[nrow][ncol] = dist + 1;
29                            dq.push_back(make_pair(dist+1,make_pair(nrow,ncol)));
30                        }else{
31                            dis[nrow][ncol] = dist;
32                            dq.push_front(make_pair(dist,make_pair(nrow,ncol)));
33                        }
34                    }
35                }
36            }
37        }
38
39        return dis[n-1][m-1] < health;
40
41    }
42};