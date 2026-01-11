// Last updated: 1/11/2026, 1:02:45 PM
class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int lo = 0, hi = n-1;
        int mini = INT_MAX;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(arr[lo] <= arr[mid]){
                mini = min(mini,arr[lo]);
                lo = mid + 1;
            }
            else{
                mini = min(arr[mid],mini);
                hi = mid - 1;
            }
        }
        return mini;
    }
};