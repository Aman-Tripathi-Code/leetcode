// Last updated: 5/9/2026, 7:26:35 PM
1class Solution {
2public:
3    vector<int> flattenAndShiftByK(vector<vector<int>>&grid, int startRow, int startCol, int n, int m, int k){
4        vector<int> arr;
5        int row = startRow, col = startCol;
6        while(row < n){
7            arr.push_back(grid[row++][col]);
8        }
9        row = n-1;
10        col++;
11        while(col < m){
12            arr.push_back(grid[row][col++]);
13        }
14        col = m-1;
15        row--;
16        while(row >= startRow){
17            arr.push_back(grid[row--][col]);
18        }
19        row = startRow;
20        col--;
21        while(col > startCol){
22            arr.push_back(grid[row][col--]);
23        }
24        int totalEle = arr.size();
25        k = k % totalEle;
26
27        reverse(arr.begin(),arr.end());
28        reverse(arr.begin(),arr.begin()+k);
29        reverse(arr.begin()+k,arr.end());
30
31        return arr;
32    }
33
34    void rotateAntiClock(int startRow, int startCol, int n, int m, vector<int>& arr, vector<vector<int>>&ans){
35        int row = startRow, col = startCol, ind = 0;
36        while(row < n){
37            ans[row++][col] = arr[ind++];
38        }
39        row = n-1;
40        col++;
41        while(col < m ){
42            ans[row][col++] = arr[ind++];
43        }
44        row--;
45        col = m-1;
46        while(row >= startRow){
47            ans[row--][col] = arr[ind++];
48        }
49        row = startRow;
50        col--;
51        while(col > startCol){
52            ans[row][col--] = arr[ind++];
53        }
54
55        
56    }
57
58    void rotate(int row, int col, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& ans,int k){
59        vector<int> layerArray = flattenAndShiftByK(grid,row, col, n, m, k);
60        rotateAntiClock(row, col, n, m, layerArray, ans);
61    }
62    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
63        int n = grid.size(), m = grid[0].size();
64        int r = n, c = m;
65        vector<vector<int>> ans(n,vector<int>(m,0));
66        for(int i = 0; i<min(m,n)/2; i++){
67            rotate(i,i,i+r,i+c,grid,ans,k);
68            r = r - 2;
69            c = c - 2;
70        }
71        return ans;
72    }
73};