// Last updated: 1/11/2026, 1:04:01 PM
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int lo = 0, hi = arr.size()-1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(arr[mid] == target){
                return mid;
            }
            //check if the left side is sorted
            else if(arr[lo] <= arr[mid]){
                if(arr[lo] <= target && arr[mid] > target){
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
            //check if right side if sorted
            else{
                if(arr[hi] >= target && arr[mid] < target){
                    lo = mid + 1;
                } 
                else hi = mid - 1;
            }
        }
        return -1;
    }
};