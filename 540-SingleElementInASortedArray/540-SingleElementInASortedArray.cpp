// Last updated: 1/11/2026, 1:01:36 PM
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(mid == 0 || mid == n-1) return nums[mid];
            else if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }
            else if(nums[mid] == nums[mid+1]){
                if(mid & 1) hi = mid - 1;
                else lo = mid + 2;
            }
            else{
                if(mid & 1) lo = mid + 1;
                else hi = mid - 2;
            }
        }
        return -1;
    }
};