// Last updated: 1/11/2026, 1:01:52 PM
// this question is an extension to the previous question in which we have to check whethe a target sum is possible 
// in the given arr
// in this question we have to check whether we can divide the element of arr in two equal halves wrt to sum
// so to tweak this question we can just apply the previous idea of find the the subset sum to k with a target sum of
// s/2 where s == sum of the whole array
class Solution {
private:
    bool findIfEqualHalves(int ind, vector<int>& nums, int sum,vector<vector<int>> &dp){
        if(sum == 0){
            return true;
        }
        if(ind == 0){
            return (nums[0]==sum);
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        bool notTake = findIfEqualHalves(ind-1,nums,sum,dp);
        bool take = false;
        if(nums[ind]<=sum){
            take = findIfEqualHalves(ind-1,nums,sum-nums[ind],dp);
        }
        return dp[ind][sum] = take|notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for(auto it:nums){
            s += it;
        }
        if(nums.size()==1){
            return false;
        }
        if(s%2){
            return false;
        }
        vector<vector<int>> dp(nums.size(),vector<int>(s+1,-1));
        s = s/2;
        int ind = nums.size()-1;
        return findIfEqualHalves(ind,nums,s,dp);
    }
};