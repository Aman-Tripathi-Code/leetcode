// Last updated: 4/28/2026, 10:47:09 PM
1class Solution {
2public:
3    int minOperations(vector<vector<int>>& grid, int x) {
4        int n = grid.size(), m = grid.front().size();
5
6        vector<int> arr(n * m);
7        int ind = 0;
8        for(int i = 0; i<n; i++){
9            for(int j = 0; j<m; j++){
10                arr[ind++] = grid[i][j];
11            }
12        }
13        sort(arr.begin(),arr.end());
14        int a = arr[0];
15        for(int i = 0; i<n*m; i++){
16            if(abs(arr[i] - a) % x != 0){
17                cout << a << ' ' << arr[i] << endl;
18                return -1;
19            }
20        }
21        int meanEle = arr[(n*m)/2], ans = 0;
22        for(int i = 0; i<n*m; i++){
23            int diff = abs(meanEle - arr[i]);
24            int numOfOp = diff/x;
25            ans += numOfOp; 
26        }
27        return ans;
28    }
29};