// Last updated: 5/20/2026, 2:07:16 PM
1using state = pair<int,int>;
2const int INF = INT_MAX;
3
4
5class Solution {
6public:
7    int dx[8] = {-1,-1,-1,0,1,1,1,0};
8    int dy[8] = {-1,0,1,1,1,0,-1,-1};
9
10    bool isValid(int x, int y, int n, vector<vector<int>>& grid){
11        return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0;
12    }
13
14    vector<state> neighbours(int row, int col, int n, vector<vector<int>>& grid){
15        vector<state> neigh;
16        for(int i = 0; i<8; i++){
17            int nrow = row + dx[i], ncol = col + dy[i];
18            if(isValid(nrow,ncol,n,grid)){
19                neigh.push_back(make_pair(nrow,ncol));
20            }
21        }
22        return neigh;
23    }
24
25    void bfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dis, int n){
26        queue<state> q;
27        q.push(make_pair(r,c));
28
29        dis[r][c] = 1;
30
31        while(!q.empty()){
32            auto [row, col] = q.front();
33            q.pop();
34
35            for(state v: neighbours(row,col,n,grid)){
36                if(dis[v.first][v.second] != INF) continue;
37                dis[v.first][v.second] = dis[row][col] + 1;
38                q.push(v);
39            }
40        }
41
42    }
43    
44    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
45        int n = grid.size();
46        vector<vector<int>> dis(n, vector<int>(n,INF)); 
47
48        if(grid[0][0] == 1) return -1;
49        bfs(0,0,grid,dis,n);
50        return (dis[n-1][n-1] == INF) ? -1 : dis[n-1][n-1];
51    }
52};