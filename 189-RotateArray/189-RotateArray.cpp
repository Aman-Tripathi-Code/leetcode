// Last updated: 1/11/2026, 1:02:37 PM
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>nums.size()){
            k = k % (nums.size());
        }
        k = nums.size() - k;
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};