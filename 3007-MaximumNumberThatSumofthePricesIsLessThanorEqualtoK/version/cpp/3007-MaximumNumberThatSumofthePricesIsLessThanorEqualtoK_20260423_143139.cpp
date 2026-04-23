// Last updated: 4/23/2026, 2:31:39 PM
1class Solution {
2public:
3    long long numberOfSetBits(long long num, int x) {
4        long long ans = 0;
5        for (long long i = x - 1; i < 60; i += x) {
6            long long full = ((num + 1) / (1LL << (i + 1)));
7            long long rem = ((num + 1) % (1LL << (i + 1)));
8            ans += (full * (1LL << i)) + max((rem - (1LL << i)), 0LL);
9        }
10        return ans;
11    }
12    long long findMaximumNumber(long long k, int x) {
13        long long lo = 0, hi = 1e15, ans = 0;
14        while (lo <= hi) {
15            long long mid = (lo + hi) / 2;
16            if (numberOfSetBits(mid, x) <= k) {
17                ans = mid;
18                lo = mid + 1;
19            } else {
20                hi = mid - 1;
21            }
22        }
23        return ans;
24    }
25};