// Last updated: 8/4/2026, 1:18:02 AM
1class Solution {
2public:
3    vector<int> findMissingElements(vector<int>& nums) {
4        int smallest = INT_MAX, largest = INT_MIN;
5        for(int i = 0; i<nums.size(); i++){
6            if(nums[i] < smallest){
7                smallest = nums[i];
8            }
9            if(nums[i] > largest){
10                largest = nums[i];
11            }
12        }
13        sort(nums.begin(),nums.end());
14        vector<int> ans;
15        for(int i = smallest; i<=largest; i++){
16            if(!binary_search(nums.begin(),nums.end(),i)){
17                ans.push_back(i);
18            }
19        }
20        return ans;
21    }
22};