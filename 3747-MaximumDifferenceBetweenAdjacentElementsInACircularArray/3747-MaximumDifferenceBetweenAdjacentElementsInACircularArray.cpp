// Last updated: 1/11/2026, 12:59:17 PM
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size(), ans = 0; 
        for(int i = 0; i<=n; i++){
            ans = max(ans, abs(nums[i%n] - nums[(i+1)%n]));
        }
        return ans;
    }
};