// Last updated: 5/1/2026, 7:27:30 PM
1class Solution {
2public:
3    int maxRotateFunction(vector<int>& nums) {
4        int n = nums.size();
5        int ans = -2e9,sum = 0, prev = 0;
6        for(int i = 0; i<n; i++){
7            prev += (i * nums[i]);
8            sum += nums[i];
9        }
10        ans = prev;
11        
12        for(int i = n-1; i>0; i--){
13            int curr = prev - (n*nums[i]) + sum;
14            ans = max(ans,curr);
15            prev = curr;
16        }
17        
18        return ans;
19    }
20};