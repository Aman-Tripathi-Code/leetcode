// Last updated: 4/9/2026, 9:40:15 AM
1class Solution {
2public:
3    void rotate(vector<vector<int>>& matrix) {
4        //transpose the matrix
5        //reverse the row
6
7        int n = matrix.size(), m = matrix.front().size();
8        for(int i = 0; i<n; i++){
9            for(int j = m-1; j >= i; j--){
10                swap(matrix[i][j],matrix[j][i]);
11            }
12        }
13        for(int i = 0; i<n; i++){
14            reverse(matrix[i].begin(), matrix[i].end());
15        }
16    }
17};