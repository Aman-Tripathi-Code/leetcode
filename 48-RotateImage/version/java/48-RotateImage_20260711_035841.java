// Last updated: 7/11/2026, 3:58:41 AM
1class Solution {
2    private void swap(int[][] matrix, int i, int j){
3        int temp = matrix[i][j];
4        matrix[i][j] = matrix[j][i];
5        matrix[j][i] = temp;
6    }
7
8    private void swap(int[][] matrix, int i, int j1, int j2){
9        int temp = matrix[i][j1];
10        matrix[i][j1] = matrix[i][j2];
11        matrix[i][j2] = temp;
12    }
13
14    private void reverse(int[][] matrix, int i, int n){
15        for(int j = 0; j<n/2; j++){
16            swap(matrix,i,j,n-1-j);
17        }
18    }
19    public void rotate(int[][] matrix) {
20        int n = matrix.length;
21        for(int i = 0; i<n; i++){
22            for(int j = 0; j<i; j++){
23                swap(matrix,i,j);
24            }
25        }
26        for(int i = 0; i<n; i++){
27            reverse(matrix,i,n);
28        }
29    }
30}