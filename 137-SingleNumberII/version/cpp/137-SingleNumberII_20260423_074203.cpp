// Last updated: 4/23/2026, 7:42:03 AM
1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int n = nums.size(), ans = 0;
5        for(int i = 0; i<32; i++){
6            long long sum = 0;
7            for(int j = 0; j<n; j++){
8                sum += (nums[j] & (1 << i));
9            }
10            if(sum % 3){
11                ans += (1 << i);
12            }
13        }
14        return ans;
15    }
16};