// Last updated: 1/11/2026, 1:03:43 PM
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(m,1),curr(m,0);
        for(int i = 1; i<n; i++){
          curr[0] = 1;
          for(int j = 1; j<m; j++){
            curr[j] = curr[j-1] + prev[j];
          }
          prev = curr;
        }
        return prev[m-1];
    }
};