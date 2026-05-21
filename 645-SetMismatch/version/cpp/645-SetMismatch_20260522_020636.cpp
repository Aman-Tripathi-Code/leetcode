// Last updated: 5/22/2026, 2:06:36 AM
1class Solution {
2public:
3    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> freq(101,0), ans;
6        for(int i = 0; i<n; i++){
7            freq[nums[i]]++;
8        }
9        for(int i = 1; i<=100; i++){
10            freq[i] += freq[i-1];
11        }
12        for(int i = 0; i<n; i++){
13            if(nums[i] == 0){
14                ans.push_back(0);
15            }else{
16                ans.push_back(freq[nums[i]-1]);
17            }
18        }
19        return ans;
20    }
21};