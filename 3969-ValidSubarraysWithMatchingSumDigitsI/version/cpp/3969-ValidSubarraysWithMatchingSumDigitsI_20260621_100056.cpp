// Last updated: 6/21/2026, 10:00:56 AM
1class Solution {
2public:
3    int isValid(long long sum, int x){
4        int first = sum % 10, last = -1;
5        while(sum >= 10){
6            sum /= 10;
7        }
8        last = sum;
9        return (first == last && first == x);
10    }
11    int countValidSubarrays(vector<int>& nums, int x) {
12        int cnt = 0, n = nums.size();
13        for (int i = 0; i < n; i++) {
14            long long sum = nums[i];
15            cnt += isValid(sum,x);
16            for (int j = i + 1; j < n; j++) {
17                sum += 1LL * nums[j];
18                cnt += isValid(sum,x);
19            }
20        }
21        return cnt;
22    }
23};