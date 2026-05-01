// Last updated: 5/1/2026, 7:25:13 PM
1class Solution {
2public:
3    int maxRotateFunction(vector<int>& nums) {
4        int n = nums.size(),ans = INT_MIN,sum = 0, prev = 0;
5        for(int i = 0; i<n; i++){
6            prev += (i * nums[i]);
7            sum += nums[i];
8        }
9        ans = prev;
10        
11        for(int i = n-1; i>0; i--){
12            int curr = prev - (n*nums[i]) + sum;
13            ans = max(ans,curr);
14            prev = curr;
15        }
16        
17        return ans;
18    }
19};