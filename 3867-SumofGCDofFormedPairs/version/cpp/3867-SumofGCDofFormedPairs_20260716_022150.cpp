// Last updated: 7/16/2026, 2:21:50 AM
1class Solution {
2public:
3    long long gcdSum(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> prefix(n,0);
6        int maxi = 0;
7        for(int i = 0; i<n; i++){
8            maxi = max(maxi,nums[i]);
9            prefix[i] = __gcd(nums[i],maxi);
10        }
11        sort(prefix.begin(),prefix.end());
12        long long sum = 0;
13        for(int i = 0; i<n/2; i++){
14            sum += 1LL*(__gcd(prefix[i],prefix[n-1-i]));
15        }
16        return sum;
17    }
18};