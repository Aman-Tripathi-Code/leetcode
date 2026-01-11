// Last updated: 1/11/2026, 1:02:55 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1; i<nums.size(); i++){
            ans ^= nums[i];
        }
        return ans;
    }
};