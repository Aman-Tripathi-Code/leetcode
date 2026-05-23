// Last updated: 5/23/2026, 3:12:46 PM
1class Solution {
2public:
3    bool check(vector<int>& nums) {
4        int n = nums.size(), cnt = 1;
5        for(int i = 0; i<2*n; i++){
6            if(nums[(i%n)] <= nums[(i+1)%n]){
7                cnt++;
8                if(cnt==n) return true;
9            }
10            else cnt = 1;
11        }
12        return cnt >= n;
13    }
14};