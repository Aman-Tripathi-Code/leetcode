// Last updated: 6/24/2026, 1:55:58 AM
1class Solution {
2private:
3    static constexpr long long MOD = 1'000'000'007;
4    using Matrix = vector<vector<long long>>;
5
6    Matrix mul(const Matrix& a, const Matrix& b) {
7        int n = a.size();
8        int m = b[0].size();
9        Matrix res(n, vector<long long>(m, 0));
10
11        for (int i = 0; i < n; i++) {
12            for (int k = 0; k < a[0].size(); k++) {
13                long long r = a[i][k];
14                if (r == 0) {
15                    continue;
16                }
17                for (int j = 0; j < m; j++) {
18                    res[i][j] = (res[i][j] + r * b[k][j]) % MOD;
19                }
20            }
21        }
22        return res;
23    }
24
25    Matrix powMul(Matrix base, long long exp, Matrix res) {
26        while (exp > 0) {
27            if (exp & 1) {
28                res = mul(res, base);
29            }
30            base = mul(base, base);
31            exp >>= 1;
32        }
33        return res;
34    }
35
36public:
37    int zigZagArrays(int n, int l, int r) {
38        int m = r - l + 1;
39        if (n == 1) {
40            return m;
41        }
42
43        int size = 2 * m;
44        Matrix u(size, vector<long long>(size, 0));
45
46        for (int i = 0; i < m; i++) {
47            for (int j = 0; j < i; j++) {
48                u[i][j + m] = 1;
49            }
50            for (int j = i + 1; j < m; j++) {
51                u[i + m][j] = 1;
52            }
53        }
54
55        Matrix dp(1, vector<long long>(size, 1));
56
57        dp = powMul(std::move(u), n - 1, std::move(dp));
58
59        long long ans = 0;
60        for (int i = 0; i < size; i++) {
61            ans = (ans + dp[0][i]) % MOD;
62        }
63
64        return ans;
65    }
66};