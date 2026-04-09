// Last updated: 4/9/2026, 9:27:38 AM
1class Solution {
2public:
3    void setZeroes(vector<vector<int>>& matrix) {
4        int n = matrix.size(), m = matrix.front().size();
5        bool rowZero = false, colZero = false;
6        for (int i = 0; i < m; i++) {
7            if (matrix[0][i] == 0) {
8                rowZero = true;
9                break;
10            }
11        }
12        for (int i = 0; i < n; i++) {
13            if (matrix[i][0] == 0) {
14                colZero = true;
15                break;
16            }
17        }
18
19        for (int i = n - 1; i >= 1; i--) {
20            for (int j = m - 1; j >= 1; j--) {
21                if (matrix[i][j] == 0) {
22                    matrix[i][0] = 0;
23                    matrix[0][j] = 0;
24                }
25            }
26        }
27
28        for (int i = n - 1; i >= 1; i--) {
29            for (int j = m - 1; j >= 1; j--) {
30                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
31                    matrix[i][j] = 0;
32                }
33            }
34        }
35        if (rowZero) {
36            for (int i = 0; i < m; i++) {
37                matrix[0][i] = 0;
38            }
39        }
40        if (colZero) {
41            for (int i = 0; i < n; i++) {
42                matrix[i][0] = 0;
43            }
44        }
45    }
46};