// Last updated: 1/11/2026, 1:02:41 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int sum = nums[l] + nums[r];
            cout << sum << endl;
            if(sum == target){
                return {l+1,r+1};
            }
            else if(sum > target){
                r--;
            }
            else l++;
        }
        return {};
    }
};