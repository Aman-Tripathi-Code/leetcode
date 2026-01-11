// Last updated: 1/11/2026, 12:59:29 PM
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n,0);
        for(int i = 1; i<n; i++){
            if(abs(nums[0]-nums[i])<=target){
                dp[i] = 1;
            }
        }
        for(int i = 1; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                if(abs(nums[i]-nums[j])<=target){
                   if(dp[i] != 0){
                       dp[j] = max(dp[j],dp[i]+1);
                   }
                }
            }
        }
        return (dp[n-1] == 0) ? -1 : dp[n-1];
    }
};