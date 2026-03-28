// Last updated: 3/29/2026, 12:32:56 AM
1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int ans = 0;
5        for(int &num: nums){
6            ans ^= num;
7        }
8        return ans;
9    }
10};