// Last updated: 4/9/2026, 10:17:24 AM
1class Solution {
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4        vector<int> spiral;
5        int n = matrix.size(), m = matrix.front().size();
6        int top = 0, bottom = n - 1, left = 0, right = m - 1;
7        while (top <= bottom && left <= right) {
8            if (top <= bottom) {
9                for (int i = left; i <= right; i++) {
10                    spiral.push_back(matrix[top][i]);
11                }
12                top++;
13            }
14
15            if (left <= right) {
16                for (int j = top; j <= bottom; j++) {
17                    spiral.push_back(matrix[j][right]);
18                }
19                right--;
20            }
21
22            if (top <= bottom) {
23                for (int i = right; i >= left; i--) {
24                    spiral.push_back(matrix[bottom][i]);
25                }
26                bottom--;
27            }
28
29            if (left <= right) {
30                for (int j = bottom; j >= top; j--) {
31                    spiral.push_back(matrix[j][left]);
32                }
33                left++;
34            }
35        }
36        return spiral;
37    }
38};