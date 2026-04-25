// Last updated: 4/25/2026, 5:57:02 PM
1class Solution {
2public:
3    int subarraysWithAtMostDistinct(vector<int>& nums, int k) {
4        int n = nums.size();
5        int head = -1, tail = 0, ans = 0, distCnt = 0;
6        unordered_map<int, int> mp;
7
8        while (tail < n) {
9            while ((head + 1 < n) &&
10                   ((distCnt < k) || mp[nums[head + 1]] >= 1)) {
11                head++;
12                if (mp[nums[head]] == 0) {
13                    distCnt++;
14                }
15                mp[nums[head]]++;
16            }
17
18            ans += (head - tail + 1);
19
20            if (tail > head) {
21                tail++;
22                head = tail - 1;
23            } else {
24                mp[nums[tail]]--;
25                if (mp[nums[tail]] == 0) {
26                    distCnt--;
27                }
28                tail++;
29            }
30        }
31        return ans;
32    }
33    int subarraysWithKDistinct(vector<int>& nums, int k) {
34        return subarraysWithAtMostDistinct(nums, k) -
35               subarraysWithAtMostDistinct(nums, k - 1);
36    }
37};