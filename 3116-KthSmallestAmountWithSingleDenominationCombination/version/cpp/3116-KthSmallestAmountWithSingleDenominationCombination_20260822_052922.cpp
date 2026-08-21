// Last updated: 8/22/2026, 5:29:22 AM
1class Solution {
2public:
3    long long gcdll(long long a, long long b) {
4        while (b != 0) {
5            long long temp = a % b;
6            a = b;
7            b = temp;
8        }
9        return a;
10    }
11
12    long long findKthSmallest(vector<int>& coins, int k) {
13        sort(coins.begin(), coins.end());
14
15        // A coin divisible by a smaller coin adds no new multiples.
16        vector<int> useful;
17        for (int coin : coins) {
18            bool redundant = false;
19
20            for (int smaller : useful) {
21                if (coin % smaller == 0) {
22                    redundant = true;
23                    break;
24                }
25            }
26
27            if (!redundant) {
28                useful.push_back(coin);
29            }
30        }
31
32        int n = useful.size();
33        int totalMasks = 1 << n;
34
35        vector<long long> subsetLCM(totalMasks);
36        vector<int> sign(totalMasks);
37
38        subsetLCM[0] = 1;
39
40        for (int mask = 1; mask < totalMasks; mask++) {
41            int bit = __builtin_ctz(mask);         
42            int previousMask = mask ^ (1 << bit);   // remove that coin
43
44            long long previousLCM = subsetLCM[previousMask];
45            long long g = gcdll(previousLCM, useful[bit]);
46
47            subsetLCM[mask] = (previousLCM / g) * useful[bit];
48
49            // Odd number of selected coins: add
50            // Even number of selected coins: subtract
51            sign[mask] = (__builtin_popcount(mask) % 2 == 1) ? 1 : -1;
52        }
53
54        auto countAmounts = [&](long long x) {
55            long long count = 0;
56
57            for (int mask = 1; mask < totalMasks; mask++) {
58                if (subsetLCM[mask] <= x) {
59                    count += sign[mask] * (x / subsetLCM[mask]);
60                }
61            }
62
63            return count;
64        };
65
66        long long low = 1;
67        long long high = 1LL * useful[0] * k;
68
69        while (low < high) {
70            long long mid = low + (high - low) / 2;
71
72            if (countAmounts(mid) >= k) {
73                high = mid;
74            } else {
75                low = mid + 1;
76            }
77        }
78
79        return low;
80    }
81};