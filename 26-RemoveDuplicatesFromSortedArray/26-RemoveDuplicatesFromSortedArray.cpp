// Last updated: 1/11/2026, 1:04:04 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        int j = 1;
        for(int i = 1 ; i<nums.size(); i++){
            if(nums[i]!=nums[i-1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};