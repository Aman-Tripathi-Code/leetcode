// Last updated: 1/11/2026, 12:59:55 PM
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int n = matrix.size(), m = matrix[0].size();
        int negCount = 0, mini = 1e9;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] < 0){
                    negCount++;
                }
                sum += abs(matrix[i][j]);
                mini = min(mini, abs(matrix[i][j]));
            }
        }
        if(negCount & 1){
            sum -= 2*mini;
        }
        return sum;
    }
};