// Last updated: 5/16/2026, 11:11:01 AM
1class Solution {
2public:
3    bool check(int mid, vector<int>& nums, int n){
4        return nums[mid] <= nums[n-1];
5    }
6    int findMin(vector<int>& nums) {
7        int n = nums.size();
8        int lo = 0, hi = n-1;
9        int ans = nums[0];
10        while(lo < n && nums[lo] == nums[hi]){
11            lo++;
12        }
13        while(lo <= hi){
14            int mid = (lo + hi)/2;
15
16            if(check(mid,nums,n)){
17                ans = nums[mid];
18                hi = mid - 1;
19            }
20            else lo = mid + 1;
21        }
22
23        return ans;
24    }
25};