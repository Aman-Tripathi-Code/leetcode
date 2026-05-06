// Last updated: 5/6/2026, 10:20:26 PM
1class Solution {
2public:
3    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
4        int n = boxGrid.size(), m = boxGrid.front().size();
5        vector<vector<char>> rotatedGrid(m,vector<char>(n,'.'));
6        vector<vector<int>> diamond(n);
7        for(int i = n-1; i>=0; i--){
8            int cnt = 0;
9            for(int j = m-1; j>=0; j--){
10                if(boxGrid[i][j] == '#'){
11                    cnt++;
12                }
13                if(boxGrid[i][j] == '*'){
14                    rotatedGrid[j][(n-1-i)] = '*';
15                    diamond[i].push_back(cnt);
16                    cnt = 0;
17                }
18            }
19            diamond[i].push_back(cnt);
20        }
21        int row = 0;
22        for(int j = n-1; j>=0; j--){
23            int ind = 0;
24            int cnt = diamond[row][ind];
25            for(int i = m-1; i>=0; i--){
26                if(cnt > 0){
27                    rotatedGrid[i][j] = '#';
28                    cnt--;
29                }
30                if(rotatedGrid[i][j] == '*'){
31                    ind++;
32                    cnt = diamond[row][ind];
33                }
34            }
35            row++;
36        }
37        return rotatedGrid;
38    }
39};