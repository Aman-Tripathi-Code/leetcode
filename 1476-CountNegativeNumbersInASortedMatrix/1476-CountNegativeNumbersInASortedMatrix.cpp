// Last updated: 1/11/2026, 1:00:21 PM
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        int r = m-1, c = 0;
        while(r >= 0 && c < n){
            if(grid[r][c] < 0){
                r--;
                count += (n-c);
            }
            else{
                c++;
            }
        }
        return count;
    }
};