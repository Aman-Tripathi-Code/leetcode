// Last updated: 1/11/2026, 1:04:03 PM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int prevIndex = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]!=val){
                    swap(nums[i],nums[prevIndex]);
                    prevIndex++;
            }
        }
        return prevIndex;
    }
};