// Last updated: 7/23/2026, 1:15:13 AM
1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n = nums.size();
5        int prefix = 1;
6        vector<int> suf(n,1);
7        suf[n-1] = nums[n-1];
8        for(int i = n-2; i>=0; i--){
9            suf[i] = nums[i] * suf[i+1];
10        }
11
12        vector<int> ans(n,1);
13        for(int i = 0; i<n-1; i++){
14            ans[i] = prefix * suf[i+1];
15            prefix *= nums[i];
16            cout << suf[i] << endl;
17        }
18        ans[n-1] = prefix;
19
20        return ans;
21        
22    }
23};