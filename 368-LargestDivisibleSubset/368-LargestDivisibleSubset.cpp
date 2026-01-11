// Last updated: 1/11/2026, 1:01:58 PM
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n);
        for(int i = 0; i<n; i++) hash[i] = i;
        int maxi = 0, lastInd = 0;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if((nums[i]%nums[j]==0) && dp[i]<dp[j]+1){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastInd = i;
            }
        }
        // for(auto it:dp){
        //     cout << it << " ";
        // }
        cout <<endl;
        vector<int> ans;
        ans.push_back(nums[lastInd]);
        while(hash[lastInd]!=lastInd){
            lastInd = hash[lastInd];
            ans.push_back(nums[lastInd]);
        }
        return ans;
    }
};