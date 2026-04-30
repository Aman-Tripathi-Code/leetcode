// Last updated: 4/30/2026, 11:53:33 PM
1class Solution {
2public:
3    int dx[4] = {-1,0,1,0};
4    int dy[4] = {0,1,0,-1};
5    bool isValid(int i, int j, int n, int m){
6        if(i >= 0 && i < n && j >= 0 && j < m){
7            return true;
8        }
9        return false;
10    }
11    void dfs(int r, int c, vector<vector<int>>& mod, vector<vector<int>>& img,int color, int n, int m, int iniColor){
12        mod[r][c] = color;
13        for(int i = 0; i<4; i++){
14            int nr = r + dx[i], nc = c + dy[i];
15            if(isValid(nr,nc,n,m)){
16                if(mod[nr][nc] == -1 && img[nr][nc] == iniColor){
17                    dfs(nr,nc,mod,img,color,n,m,iniColor);
18                }
19            }
20        }
21    }
22    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
23        int n = image.size(), m = image[0].size();
24        vector<vector<int>> modified(n,vector<int>(m,-1));      
25        int iniColor = image[sr][sc];        
26        dfs(sr,sc,modified,image,color,n,m,iniColor);
27        for(int i = 0; i<n; i++){
28            for(int j = 0; j<m; j++){
29                if(modified[i][j] == -1){
30                    modified[i][j] = image[i][j];
31                }
32            }
33        }
34        return modified;
35    }
36};