// Last updated: 4/26/2026, 3:09:34 PM
1class Solution {
2public:
3    vector<vector<int>> generate(int numRows) {
4        int n = numRows;
5        vector<vector<int>> triangle(n);
6        for(int i = 0; i<n; i++){
7            triangle[i].resize(i+1);
8            for(int j = 0; j<i+1; j++){
9                if(j==0 || j == i){
10                   triangle[i][j] = 1; 
11                }else{
12                    triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
13                }
14            }
15        }
16        return triangle;
17    }
18};