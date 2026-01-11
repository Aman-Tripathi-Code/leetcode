// Last updated: 1/11/2026, 12:59:30 PM
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mini = 1e9;
        for(int i = 0; i<n-1; i++){
            mini = min(mini,(nums[i+1]-nums[i]));
        }
        return mini;
    }
};