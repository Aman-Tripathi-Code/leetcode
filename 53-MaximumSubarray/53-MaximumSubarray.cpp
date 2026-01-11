// Last updated: 1/11/2026, 1:03:47 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1e9;
        int prev = 0, curr = 0;
        for(int i = 0; i<n; i++){
            int take = prev + nums[i];
            int notTake = nums[i];
            curr = max(take,notTake);
            maxi = max(curr,maxi);
            prev = curr;
        }
        return maxi;
    }
};