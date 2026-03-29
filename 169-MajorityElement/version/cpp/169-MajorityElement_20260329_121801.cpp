// Last updated: 3/29/2026, 12:18:01 PM
1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        int maj = nums[0], cnt = 1;
5        for(int i = 1; i<nums.size(); i++){
6            if(nums[i] == maj){
7                cnt++;
8            }else{
9                cnt--;
10                if(cnt == 0){
11                     maj = nums[i];
12                     cnt = 1;
13                }
14            }
15        }
16        return maj;
17    }
18};