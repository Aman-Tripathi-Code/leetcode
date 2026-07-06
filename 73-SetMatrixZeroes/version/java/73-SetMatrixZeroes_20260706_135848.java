// Last updated: 7/6/2026, 1:58:48 PM
1class Solution {
2    public void setZeroes(int[][] matrix) {
3        boolean flag = false;
4        int n = matrix.length, m = matrix[0].length;
5        for(int j = 0; j<m; j++){
6            if(matrix[0][j] == 0){
7                flag = true;
8                break;
9            }
10        }
11        for(int i = 0; i<n; i++){
12            if(matrix[i][0] == 0){
13                matrix[0][0] = 0;
14                break;
15            }
16        }
17        for (int i = n - 1; i >= 1; i--) {
18            for (int j = m - 1; j >= 1; j--) {
19                if (matrix[i][j] == 0) {
20                    matrix[i][0] = 0;
21                    matrix[0][j] = 0;
22                }
23            }
24        }
25        // for(int i = 0; i<n; i++){
26        //     for(int j = 0; j<m; j++){
27        //         System.out.print(matrix[i][j] + " ");
28        //     }
29        //     System.out.println();
30        // }
31
32        for(int i = n-1; i>=1; i--){
33            for(int j = m-1; j>=1; j--){
34                if(matrix[i][0] == 0 || matrix[0][j] == 0){
35                    matrix[i][j] = 0;
36                }
37            }
38        }
39
40        for(int i = 0; i<n; i++){
41            if(matrix[0][0] == 0){
42                matrix[i][0] = 0;
43            }
44        }
45
46
47        for(int i = 0; i<m; i++){
48            if(flag){
49                matrix[0][i] = 0;
50            }
51        }
52        
53    }
54}