// Last updated: 8/4/2026, 1:19:35 AM
1class Solution {
2public:
3    vector<int> findMissingElements(vector<int>& nums) {
4        int smallest = INT_MAX, largest = INT_MIN;
5        vector<int> hs(101,0);
6        for(int i = 0; i<nums.size(); i++){
7            if(nums[i] < smallest){
8                smallest = nums[i];
9            }
10            if(nums[i] > largest){
11                largest = nums[i];
12            }
13            hs[nums[i]]++;
14        }
15        vector<int> ans;
16        for(int i = smallest; i<=largest; i++){
17            if(hs[i] == 0){
18                ans.push_back(i);
19            }
20        }
21        return ans;
22    }
23};