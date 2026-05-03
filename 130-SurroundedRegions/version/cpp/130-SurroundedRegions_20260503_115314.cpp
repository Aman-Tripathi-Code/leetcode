// Last updated: 5/3/2026, 11:53:14 AM
1vector<vector<int>> vis;
2
3
4class Solution {
5public:
6
7    int dx[4] = {-1,0,1,0};
8    int dy[4] = {0,1,0,-1};
9
10    bool isValid(int i, int j, int n, int m){
11        return (i >=0 && i < n && j >=0 && j < m);
12    }
13
14    void dfs(int row, int col, vector<vector<char>>&board, int n, int m){
15        vis[row][col] = 1;
16
17        for(int i = 0; i<4; i++){
18            int nr = row + dx[i], nc = col + dy[i];
19            if(isValid(nr,nc,n,m)){
20                if(!vis[nr][nc] && board[nr][nc] == 'O'){
21                    dfs(nr,nc,board,n,m);
22                }
23            }
24        }
25    }
26
27    void solve(vector<vector<char>>& board) {
28        int n = board.size(), m = board.front().size();
29        vis.assign(n,vector<int>(m,0));
30
31        for(int i = 0; i<m; i++){
32            if(!vis[0][i] && board[0][i] == 'O'){
33                dfs(0,i,board,n,m);
34            }
35            if(!vis[n-1][i] && board[n-1][i] == 'O'){
36                dfs(n-1,i,board,n,m);
37            }
38        }
39
40        for(int i = 0; i<n; i++){
41            if(!vis[i][0] && board[i][0] == 'O'){
42                dfs(i,0,board,n,m);
43            }
44            if(!vis[i][m-1] && board[i][m-1] == 'O'){
45                dfs(i,m-1,board,n,m);
46            }
47        }
48
49        for(int i = 0; i<n; i++){
50            for(int j = 0; j<m; j++){
51                if(vis[i][j] == 0 && board[i][j] == 'O'){
52                    board[i][j] = 'X';
53                }
54            }
55        }
56
57    }
58};