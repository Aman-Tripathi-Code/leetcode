// Last updated: 5/1/2026, 7:27:16 PM
1class Solution {
2public:
3    int maxRotateFunction(vector<int>& nums) {
4        int n = nums.size();
5        int ans = -2e9;
6        int sum = 0, prev = 0;
7        for(int i = 0; i<n; i++){
8            prev += (i * nums[i]);
9            sum += nums[i];
10        }
11        ans = prev;
12        
13        for(int i = n-1; i>0; i--){
14            int curr = prev - (n*nums[i]) + sum;
15            ans = max(ans,curr);
16            prev = curr;
17        }
18        
19        return ans;
20    }
21};