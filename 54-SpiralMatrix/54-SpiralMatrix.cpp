// Last updated: 1/11/2026, 1:03:46 PM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        int top = 0, bottom = n-1, left = 0, right = m-1;
        vector<int> ans;
        while((top <= bottom && left <= right)){

            for(int i = left; i<=right; i++){
                ans.push_back(A[top][i]);
            }
            ++top;

            for(int i = top; i<=bottom; i++){
                ans.push_back(A[i][right]);
            }
            --right;

            
            if(top<=bottom){
                for(int i = right; i>=left; i--){
                    ans.push_back(A[bottom][i]);
                }
            }
            --bottom;
            
            if(left<=right){
                for(int i = bottom; i>=top; i--){
                    ans.push_back(A[i][left]);
                }
            }
            ++left;

        }
        return ans;
    }
};