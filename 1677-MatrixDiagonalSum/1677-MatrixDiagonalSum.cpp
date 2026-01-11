// Last updated: 1/11/2026, 1:00:07 PM
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sz = mat.size();
        int j = sz-1;
        int sum = 0;
        for(int i = 0; i<sz; i++){
            sum += (mat[i][i] + mat[i][j]);
            j--;
        }
        return (sz & 1) ? sum - mat[sz/2][sz/2] : sum;
    }
};