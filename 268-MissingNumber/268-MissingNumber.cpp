// Last updated: 1/11/2026, 1:02:08 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            ans ^= nums[i];
        }
        for(int i = 0; i<=nums.size(); i++){
            ans^=i;
        }
        return ans;
    }
};