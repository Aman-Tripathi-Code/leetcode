// Last updated: 1/11/2026, 1:03:29 PM
class Solution {
public:
    bool search(vector<int>& arr, int key) {
        int lo = 0, hi = arr.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(arr[mid] == key) return 1;
            //work when the mid is smaller than lo and lo and hi element are same
            else if(arr[lo] == arr[hi]){
                if(arr[lo] == key) return 1;
                else{
                    lo++;
                    hi--;
                }
            }
            else if(arr[lo] <= arr[mid]){
                if(arr[lo] <= key && arr[mid] > key){
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
            else{
                if(arr[hi] >= key && arr[mid] < key){
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
        }
        return 0;
    }
};