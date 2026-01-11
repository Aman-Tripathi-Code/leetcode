// Last updated: 1/11/2026, 1:01:41 PM
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++) sum+= nums[i];
        int d = sum+target;
        if(d&1||d<0){
            return 0;
        }
        d = d/2;
        //dp state:- number of way to get sum j when on index i
        vector<vector<int>> dp(n,vector<int>(d+1,0));

        for(int i =0;i<n; i++) dp[i][0] = 1;

           if(nums[0]<=d){
                if(nums[0]==0){
                    dp[0][nums[0]] = 2;
                }
                else dp[0][nums[0]] = 1;
           }

        for(int i = 1; i<n; i++){
            for(int j = 0; j<d+1; j++){
                int notTake = dp[i-1][j];
                int take = 0;
                if(nums[i]<=j){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = notTake + take;
            }
        }
        return dp[n-1][d];

    }
};