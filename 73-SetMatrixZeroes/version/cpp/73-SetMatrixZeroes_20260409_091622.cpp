// Last updated: 4/9/2026, 9:16:22 AM
1class Solution {
2public:
3    void setZeroes(vector<vector<int>>& matrix) {
4        int n = matrix.size(), m = matrix.front().size();
5        int flag = false;
6        for(int i = 0; i<m; i++){
7            if(matrix[0][i] == 0){
8                flag = true;
9                break;
10            }
11        }
12        for(int i = 0; i<n; i++){
13            if(matrix[i][0] == 0){
14                matrix[0][0] = 0;
15            }
16        }
17
18        for(int i = n-1; i>=1; i--){
19            for(int j = m-1; j>=1; j--){
20                if(matrix[i][j] == 0){
21                    matrix[i][0] = 0;
22                    matrix[0][j] = 0;
23                }
24            }
25        }
26
27        for(int i = n-1; i>=0; i--){
28            for(int j = m-1; j>=0; j--){
29                if(i == 0 || j == 0){
30                    if(i == 0){
31                        if(flag == true){
32                            matrix[0][j] = 0;
33                        }
34                    }else{
35                        if(matrix[0][0] == 0){
36                            matrix[i][0] = 0;
37                        }
38                    }
39                }else{
40                    if(matrix[0][j] == 0 || matrix[i][0] == 0){
41                        matrix[i][j] = 0;
42                    }
43                }
44            }
45        }
46
47    }
48};