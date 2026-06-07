// Last updated: 6/8/2026, 2:07:55 AM
class Solution {
public:
    long long numberOfSetBits(long long num, int x) {
        long long ans = 0;
        for (long long i = x - 1; i < 60; i += x) {
            long long full = ((num + 1) / (1LL << (i + 1)));
            long long rem = ((num + 1) % (1LL << (i + 1)));
            ans += (full * (1LL << i)) + max((rem - (1LL << i)), 0LL);
        }
        return ans;
    }
    long long findMaximumNumber(long long k, int x) {
        long long lo = 0, hi = 1e15, ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (numberOfSetBits(mid, x) <= k) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};