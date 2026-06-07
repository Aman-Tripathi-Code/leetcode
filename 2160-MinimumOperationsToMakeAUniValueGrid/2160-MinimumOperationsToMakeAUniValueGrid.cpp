// Last updated: 6/8/2026, 2:08:28 AM
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid.front().size();

        vector<int> arr(n * m);
        int ind = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                arr[ind++] = grid[i][j];
            }
        }
        sort(arr.begin(),arr.end());
        int a = arr[0];
        for(int i = 0; i<n*m; i++){
            if(abs(arr[i] - a) % x != 0){
                cout << a << ' ' << arr[i] << endl;
                return -1;
            }
        }
        int meanEle = arr[(n*m)/2], ans = 0;
        for(int i = 0; i<n*m; i++){
            int diff = abs(meanEle - arr[i]);
            int numOfOp = diff/x;
            ans += numOfOp; 
        }
        return ans;
    }
};