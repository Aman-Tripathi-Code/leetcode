// Last updated: 4/3/2026, 12:49:09 AM
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n = nums.size();
5        int lo = 0, hi = n - 1, ans = -1;
6        while (lo <= hi) {
7            int mid = lo + (hi - lo) / 2;
8            if (nums[mid] == target){   
9                return mid;
10            }else if(nums[mid] < target){
11                lo = mid + 1;
12            }else{
13                hi = mid - 1;
14            }
15        }
16        return -1;
17    }
18};