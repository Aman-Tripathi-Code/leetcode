// Last updated: 1/11/2026, 1:00:52 PM
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i<n-2; i++){
            if(nums[i] == nums[i+1] || nums[i] == nums[i+2]){
               return nums[i];
            }
        }
        return nums[n-1];
    }
};