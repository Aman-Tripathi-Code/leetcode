// Last updated: 1/11/2026, 1:03:34 PM
class Solution {
private:
    int lowerBound(vector<vector<int>> &matrix, int target){
        int n = matrix.size();
        int lo = -1, hi = n;
        while(hi-lo>1){
            int mid = (hi+lo)>>1;
            if(matrix[mid][0]<=target){
                lo = mid;
            }
            else{
                hi = mid;
            }
        }
        return lo;
    }
    bool binarySearch(vector<vector<int>> &matrix, int target,int ind){
        int m = matrix[0].size();
        int lo = -1, hi = m;
        while(hi-lo>1){
            int mid = (hi+lo)>>1;
            if(matrix[ind][mid]==target){
                return true;
            }
            if(matrix[ind][mid]>target){
                hi = mid;
            }
            else{
                lo = mid;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int ind = lowerBound(matrix,target);
        cout << ind << endl;
        if(ind==-1||ind==n){
            return false;
        }        
        return binarySearch(matrix,target,ind); 
    }
};