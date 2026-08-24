// Last updated: 8/25/2026, 2:01:16 AM
1class Solution {
2public:
3    int missingMultiple(vector<int>& nums, int k) {
4        int n = nums.size();
5        int hs[101] = {0};
6
7        for(int i = 0; i<n; i++){
8            if(nums[i] % k == 0){
9                hs[nums[i]] = 1;
10            }
11        }
12
13        for(int i = k; i<=100; i+=k){
14            // cout << i << ' ' << hs[i] << endl;
15            if(hs[i] == 0){
16                return i;
17            }
18        }
19        return ((100/k)+1) * k;
20    }
21};