// Last updated: 6/8/2026, 2:07:59 AM
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size(), maxi = 0;
        if(n == 1) return false;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n-2; i++){
            if(nums[i] != (i+1)){
                return false;
            }
        }
        return (nums[n-2] == nums[n-1]) && (nums[n-1] == n-1);
    }
};