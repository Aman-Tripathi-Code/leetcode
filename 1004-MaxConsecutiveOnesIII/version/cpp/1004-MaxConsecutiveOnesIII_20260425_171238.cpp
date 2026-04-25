// Last updated: 4/25/2026, 5:12:38 PM
1class Solution {
2public:
3    int longestOnes(vector<int>& nums, int k) {
4        int n = nums.size();
5
6        int head = -1, tail = 0;
7        int ans = 0;
8        int cnt = 0;
9
10        while(tail < n){
11            while((head + 1 < n) && (cnt < k || (nums[head + 1] == 1))){
12                head++;
13                if(nums[head] == 0){
14                    cnt++;
15                }
16            }
17
18            ans = max(ans, (head - tail + 1));
19
20            if(tail > head){
21                tail++;
22                head = tail - 1;
23            }else{
24                if(nums[tail] == 0){
25                    cnt--;
26                }
27                tail++;
28            }
29        }
30        return ans;
31    }
32};