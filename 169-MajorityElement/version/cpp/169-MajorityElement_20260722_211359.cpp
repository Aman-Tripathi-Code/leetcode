// Last updated: 7/22/2026, 9:13:59 PM
1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        int cand = nums[0], cnt = 1, n = nums.size();
5        for(int i = 1; i<n; i++){
6            if(nums[i] == cand){
7                cnt++;
8            }else{
9                cnt--;
10                if(cnt == 0){
11                    cand = nums[i];
12                    cnt = 1;
13                }
14            }
15        }
16        cnt = 0;
17        for(int i = 0; i<n; i++){
18            if(nums[i] == cand){
19                cnt++;
20            }
21        }
22        return (cnt > n/2) ? cand : -1;
23    }
24};