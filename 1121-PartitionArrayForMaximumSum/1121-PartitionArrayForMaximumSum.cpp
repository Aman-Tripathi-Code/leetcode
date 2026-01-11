// Last updated: 1/11/2026, 1:00:38 PM
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int i = n-1; i>=0; i--){
            int maxElement = -1e9, maxSum = -1e9 , len = 0;
            for(int j = i; j<min(n,i+k) ; j++){
                len++;
                maxElement = max(maxElement,arr[j]);
                int ans = (len*maxElement) + dp[j+1];
                maxSum = max(ans,maxSum);
            }
            dp[i] = maxSum;
        }
        for(auto it:dp){
            cout << it << " ";
        }
        return dp[0];
    }
};