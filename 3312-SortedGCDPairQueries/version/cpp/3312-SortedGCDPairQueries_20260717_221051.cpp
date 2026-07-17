// Last updated: 7/17/2026, 10:10:51 PM
1class Solution {
2public:
3    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
4        int m = *max_element(nums.begin(), nums.end());
5        vector<long long> cnt(m + 1);
6        for (int num : nums) {
7            cnt[num]++;
8        }
9        for (int i = 1; i <= m; i++) {
10            for (int j = i * 2; j <= m; j += i) {
11                cnt[i] += cnt[j];
12            }
13        }
14        for (int i = 1; i <= m; i++) {
15            cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
16        }
17        for (int i = m; i >= 1; i--) {
18            for (int j = i * 2; j <= m; j += i) {
19                cnt[i] -= cnt[j];
20            }
21        }
22        for (int i = 1; i <= m; i++) {
23            cnt[i] += cnt[i - 1];
24        }
25        vector<int> ans;
26        for (long long q : queries) {
27            q++;
28            int pos = lower_bound(cnt.begin(), cnt.end(), q) - cnt.begin();
29            ans.push_back(pos);
30        }
31        return ans;
32    }
33};