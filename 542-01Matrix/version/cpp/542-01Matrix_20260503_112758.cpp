// Last updated: 5/3/2026, 11:27:58 AM
1#define F first
2#define S second
3using state = pair<int,int>;
4vector<vector<int>> dis;
5const int INF = INT_MAX;
6int dx[] = {-1,0,1,0};
7int dy[] = {0,1,0,-1};
8
9
10class Solution {
11public:
12    bool isValid(int r, int c, int n, int m){
13        return (r >= 0 && r < n && c >=0 && c < m);
14    }
15    vector<state> neighbours(state st,vector<vector<int>>&mat, int n, int m){
16        vector<state> neigh;
17        for(int i = 0; i<4; i++){
18            int nr = st.F + dx[i], nc = st.S + dy[i];
19            if(isValid(nr,nc,n,m)){
20                if(dis[nr][nc] == INF && mat[nr][nc] == 1){
21                    neigh.push_back({nr,nc});
22                }
23            }
24        }
25        return neigh;
26    }
27
28    void bfs(vector<vector<int>> &mat,int n ,int m){
29        queue<state> q;
30
31        for(int i = 0; i<n; i++){
32            for(int j = 0; j<m; j++){
33                if(mat[i][j] == 0){
34                    q.push({i,j});
35                    dis[i][j] = 0;
36                }
37            }
38        }
39
40        while(!q.empty()){
41            state s = q.front();
42            q.pop();
43
44            for(state v: neighbours(s,mat,n,m)){
45                if(dis[v.F][v.S] > dis[s.F][s.S] + 1){
46                    q.push({v.F,v.S});
47                    dis[v.F][v.S] = dis[s.F][s.S] + 1;
48                }
49            }
50
51        }
52    }
53    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
54        int n = mat.size(), m  = mat.front().size();
55        dis.assign(n,vector<int>(m,INF));
56
57        bfs(mat,n,m);
58
59        return dis;
60
61    }
62};