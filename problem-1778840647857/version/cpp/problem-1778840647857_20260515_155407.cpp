// Last updated: 5/15/2026, 3:54:07 PM
1const int ZERO = []()
2{
3std::ios_base::sync_with_stdio(false);
4std::cin.tie(nullptr);
5return 0;
6}();
7class Solution {
8public:
9    long long binpow(long long a, long long b, int mod) {
10        long long res = 1;
11        while (b) {
12            if (b & 1) {
13                res = (res * a) % mod;
14                b--;
15            } else {
16                a = (a * a) % mod;
17                b >>= 1;
18            }
19        }
20        return res % mod;
21    }
22    int concatenatedBinary(int n) {
23        int prev = 0, mod = 1e9 + 7;
24        long long ans = 0;
25        for (int i = n; i > 0; i--) {
26            int curr = 0;
27            long long num = i;
28            ans = (ans + (num * binpow(2,prev,mod))%mod) % mod;
29            while (num) {
30                num = num >> 1;
31                curr++;
32            }
33            prev += curr;
34        }
35        return ans % mod;
36    }
37};