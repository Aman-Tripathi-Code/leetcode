// Last updated: 7/23/2026, 10:28:45 AM
1class Solution {
2public:
3    bool check(int mid, vector<int>& arr){
4        return arr[mid] < arr[mid + 1] && arr[mid] > arr[mid - 1];
5    }
6    int peakIndexInMountainArray(vector<int>& arr) {
7        int n = arr.size();
8        if(arr[0] > arr[1]) return 0;
9        if(arr[n-1] > arr[n-2]) return n-1;
10        int lo = 1, hi = n-2;
11        while(lo <= hi){
12            int mid = (lo + hi)/2;
13            if(check(mid,arr)){
14                lo = mid + 1;
15            }else{
16                hi = mid - 1;
17            }
18        }   
19        return lo;
20    }
21};