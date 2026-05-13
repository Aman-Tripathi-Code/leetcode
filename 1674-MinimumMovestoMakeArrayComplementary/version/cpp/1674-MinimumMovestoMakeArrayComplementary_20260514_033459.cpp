// Last updated: 5/14/2026, 3:34:59 AM
1class Solution {
2public:
3    int minMoves(vector<int>& nums, int limit) {
4        int n = nums.size();
5        vector<int> sweep(2*limit+2,0);
6
7        for(int i = 0; i<n/2; i++){
8            int a = min(nums[i],nums[n-1-i]);
9            int b = max(nums[i],nums[n-1-i]);
10            sweep[2] += 2;
11            sweep[a + 1] -= 1;
12            sweep[a + b] -= 1;
13            sweep[a + b + 1] += 1;
14            sweep[b + limit + 1] += 1;
15        }
16        int cnt = 0, mini = 1e9;
17        for(int i = 2; i<=2*limit; i++){
18            cnt += sweep[i];
19            mini = min(mini,cnt);
20        }
21        return mini;
22    }
23};