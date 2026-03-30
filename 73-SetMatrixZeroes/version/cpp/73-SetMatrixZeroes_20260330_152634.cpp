// Last updated: 3/30/2026, 3:26:34 PM
1class Solution {
2public:
3    void setZeroes(vector<vector<int>>& matrix) {
4        int n = matrix.size(), m = matrix.front().size();
5        vector<int> row(m,1), col(n,1);
6        bool flag = (matrix[0][0] == 0);
7        for(int i = 0; i<n; i++){
8            for(int j = 0; j<m; j++){
9                if(matrix[i][j] == 0){
10                    row[j] = 0;
11                    col[i] = 0;
12                }
13            }
14        }
15        for(int i = 0; i<n; i++){
16            for(int j = 0; j<m; j++){
17                if(matrix[i][j] != 0){
18                    if(row[j] == 0 || col[i] == 0) matrix[i][j] = 0;
19                }
20            }
21        }
22    }
23};