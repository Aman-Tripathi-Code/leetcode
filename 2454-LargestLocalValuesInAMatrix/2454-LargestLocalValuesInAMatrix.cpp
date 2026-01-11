// Last updated: 1/11/2026, 12:59:41 PM
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n-2,vector<int>(n-2));
        int maxi = 0; 
        int row = 0, col = 0;
        for(int r = 0; r<n-2; r++){
            for(int c = 0; c<n-2; c++){
                for(int j = r; j<r+3; j++){
                    for(int k = c ; k<c+3; k++){
                        maxi = max(maxi,grid[j][k]);
                    }
                }
                maxLocal[row][col] = maxi;
                maxi =0;
                col++;
            }
            col = 0;
            row++;
        }
        return maxLocal;
    }
};