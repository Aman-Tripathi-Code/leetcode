// Last updated: 5/6/2026, 10:37:44 PM
1class Solution {
2public:
3    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
4        int n = boxGrid.size(), m = boxGrid.front().size();
5
6        for(int i = 0; i<n; i++){
7            int writePos = m-1;
8            for(int j = m-1; j>=0; j--){
9                if(boxGrid[i][j] == '*'){
10                    writePos = j-1;
11                }
12                if(boxGrid[i][j] == '#'){
13                    swap(boxGrid[i][j], boxGrid[i][writePos]);
14                    writePos--;
15                }
16            }
17        }
18        vector<vector<char>> rotatedGrid(m,vector<char>(n,'.'));
19        for(int i = 0; i < n; i++){
20            for(int j = 0; j < m; j++){
21                rotatedGrid[j][(n-1-i)] = boxGrid[i][j];
22            }
23        }
24        return rotatedGrid;
25    }
26};