// Last updated: 8/25/2026, 2:03:03 AM
1class Solution {
2public:
3    int missingMultiple(vector<int>& nums, int k) {
4        int n = nums.size();
5        bool hs[101] = {};
6
7        for(int i = 0; i<n; i++){
8            if(nums[i] % k == 0){
9                hs[nums[i]] = true;
10            }
11        }
12
13        for(int i = k; i<=100; i+=k){
14            if(hs[i] == false){
15                return i;
16            }
17        }
18        return ((100/k)+1) * k;
19    }
20};