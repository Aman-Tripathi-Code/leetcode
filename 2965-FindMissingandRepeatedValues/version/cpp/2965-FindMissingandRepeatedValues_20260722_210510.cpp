// Last updated: 7/22/2026, 9:05:10 PM
1class Solution {
2public:
3    int findSetBit(int n){
4        for(int i = 0; i<32; i++){
5            if(n & (1 << i)){
6                return i;
7            }
8        }
9        return 32;
10    }
11    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
12        int x = 0, y = 0;
13        int n = grid.size(), m = grid.front().size();
14        int cnt = 1, xr = 0;
15        for(int i = 0; i<n; i++){
16            for(int j = 0; j<m; j++){
17                xr ^= grid[i][j];
18                xr ^= cnt;
19                cnt++;
20            }
21        }
22        int pos = findSetBit(xr);
23        int one = 0, zero = 0;
24        for(int i = 0; i<n; i++){
25            for(int j = 0; j<m; j++){
26                if(grid[i][j] & (1 << pos)){
27                    one ^= grid[i][j];
28                }else{
29                    zero ^= grid[i][j];
30                }
31            }
32        }
33        for(int i = 1; i<=n*m; i++){
34            if(i & (1 << pos)){
35                one ^= i;
36            }else{
37                zero ^= i;
38            }
39        }
40        for(int i = 0; i<n; i++){
41            for(int j = 0;j<n;j++){
42                if(one == grid[i][j]){
43                    return {one,zero};
44                }
45            }
46        }
47        return {zero,one};
48    }
49};