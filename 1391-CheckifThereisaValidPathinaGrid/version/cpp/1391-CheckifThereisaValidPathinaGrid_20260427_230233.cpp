// Last updated: 4/27/2026, 11:02:33 PM
1class Solution {
2public:
3    vector<vector<pair<int,int>>> dir;
4    vector<vector<vector<int>>> isValid;
5    void build(){
6        dir[1].push_back({0,-1});
7        dir[1].push_back({0,1});
8
9        dir[2].push_back({-1,0});
10        dir[2].push_back({1,0});
11
12        dir[3].push_back({0,-1});
13        dir[3].push_back({1,0});
14
15        dir[4].push_back({0,1});
16        dir[4].push_back({1,0});
17
18        dir[5].push_back({0,-1});
19        dir[5].push_back({-1,0});
20        
21        dir[6].push_back({-1,0});
22        dir[6].push_back({0,1});
23
24        isValid[1].push_back({1,4,6});
25        isValid[1].push_back({1,3,5});
26
27        isValid[2].push_back({2,3,4});
28        isValid[2].push_back({2,5,6});
29
30        isValid[3].push_back({1,4,6});
31        isValid[3].push_back({2,5,6});
32
33        isValid[4].push_back({1,3,5});
34        isValid[4].push_back({2,5,6});
35
36        isValid[5].push_back({1,4,6});
37        isValid[5].push_back({2,3,4});
38
39        isValid[6].push_back({2,3,4});
40        isValid[6].push_back({1,3,5});
41
42    }
43    bool check(int i, int j, int n, int m){
44        if((i >= 0 && i < n) && ((j >= 0 && j < m))){
45
46            return true;
47        }
48        return false;
49    }
50    bool isValidPath(int curr, int ind, int next){
51        for(int i = 0; i<3; i++){
52            if(next == isValid[curr][ind][i]){
53                return true;
54            }
55        }
56        return false;
57    }
58    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m){
59        vis[i][j] = 1;
60        int street = grid[i][j];
61        for(int k = 0; k<2; k++){
62            int nrow = i + dir[street][k].first, ncol = j + dir[street][k].second;
63            if(check(nrow,ncol,n,m)){
64                int newStreet = grid[nrow][ncol];
65                if(isValidPath(street,k,newStreet)){
66                    if(!vis[nrow][ncol]){
67                        dfs(nrow,ncol,vis,grid,n,m);
68                    }
69                }
70            }
71        }
72    }
73    bool hasValidPath(vector<vector<int>>& grid) {
74        int n = grid.size(), m = grid.front().size();
75        dir.resize(7);
76        isValid.resize(7);
77        vector<vector<int>> vis(n,vector<int>(m,0));
78        build();
79
80        dfs(0,0,vis,grid,n,m);
81        return vis[n-1][m-1];
82    }
83};