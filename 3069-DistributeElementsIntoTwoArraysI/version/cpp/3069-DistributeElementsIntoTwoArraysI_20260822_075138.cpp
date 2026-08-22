// Last updated: 8/22/2026, 7:51:38 AM
1class Solution {
2public:
3    vector<int> resultArray(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> a, b;
6        a.push_back(nums[0]);
7        b.push_back(nums[1]);
8        for(int i = 2; i<n; i++){
9            if(a.back() > b.back()){
10                a.push_back(nums[i]);
11            }else{
12                b.push_back(nums[i]);
13            }
14        }
15        for(int i = 0; i<b.size(); i++){
16            a.push_back(b[i]);
17        }
18        return a;
19    }
20};