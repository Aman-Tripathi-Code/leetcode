// Last updated: 5/16/2026, 1:33:31 PM
1class Solution {
2public:
3    vector<int> getConcatenation(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> conCat;
6        for(int i = 0; i<2*n; i++){
7            conCat.push_back(nums[i%n]);
8        }
9        return conCat;
10    }
11};