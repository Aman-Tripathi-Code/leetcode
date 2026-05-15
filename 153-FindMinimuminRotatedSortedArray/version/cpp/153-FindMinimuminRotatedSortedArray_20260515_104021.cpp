// Last updated: 5/15/2026, 10:40:21 AM
1class Solution {
2public:
3    bool check(int mid, vector<int>&nums, int n){
4        return nums[mid] < nums[n-1];
5    }
6    int findMin(vector<int>& nums) {
7        int n = nums.size();
8        int lo = 0, hi = n-1, ans = nums[n-1];
9
10        while(lo <= hi){
11            int mid = (lo + hi) / 2;
12
13            if(check(mid, nums, n)){
14                hi = mid - 1;
15                ans = nums[mid];
16            }else{
17                lo = mid + 1;
18            }
19        }
20
21        return ans;
22    }
23};