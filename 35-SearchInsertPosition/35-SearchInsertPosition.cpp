// Last updated: 1/11/2026, 1:03:59 PM
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
         int lo = -1 , hi = nums.size();
        
        while(hi - lo > 1){
            int mid = lo + (hi - lo)/2;
            
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) lo = mid;
            else hi = mid;
        }
        return lo + 1;
    }
};