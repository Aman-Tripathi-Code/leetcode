// Last updated: 7/9/2026, 1:19:36 AM
1class Solution {
2    long binPow(long a, long b, int m) {
3        long res = 1;
4        while (b > 0) {
5            if ((b & 1) > 0) {
6                res = (a * res) % m;
7                b -= 1;
8            }
9            b /= 2;
10            a = (a * a) % m;
11        }
12        return res % m;
13    }
14
15    public int[] sumAndMultiply(String s, int[][] queries) {
16        int n = s.length();
17        int mod = (int) 1e9 + 7;
18        long[] preX = new long[n + 1];
19        long[] preSum = new long[n + 1];
20        long[] preCount = new long[n + 1];
21
22        for (int i = 1; i <= n; i++) {
23            int digit = s.charAt(i - 1) - '0';
24            if (digit != 0) {
25                preX[i] = ((preX[i - 1] * 10)%mod + digit) % mod;
26                preSum[i] = (preSum[i - 1] + digit) % mod;
27                preCount[i] = (preCount[i - 1] + 1) % mod;
28            } else {
29                preX[i] = preX[i - 1];
30                preSum[i] = preSum[i - 1];
31                preCount[i] = preCount[i - 1];
32            }
33        }
34        int m = queries.length;
35        int[] ans = new int[m];
36        for (int i = 0; i < m; i++) {
37            int l = queries[i][0], r = queries[i][1];
38            l++;
39            r++;
40            long count = preCount[r] - preCount[l - 1];
41            long sum = preSum[r] - preSum[l - 1];
42            long x = (preX[r]%mod - (binPow(10, count, mod) * preX[l - 1]%mod)%mod + mod) % mod;
43            ans[i] = (int) (x%mod * sum%mod) % mod;
44        }
45        return ans;
46    }
47}