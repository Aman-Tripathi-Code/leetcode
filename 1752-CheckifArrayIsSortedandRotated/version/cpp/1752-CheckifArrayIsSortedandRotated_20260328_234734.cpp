// Last updated: 3/28/2026, 11:47:34 PM
1class Solution {
2public:
3    bool check(vector<int>& nums) {
4        int n = nums.size();
5        if(n == 1) return true;
6        
7        int cnt = 1;
8        for(int i = 0; i<2*n; i++){
9            if(nums[i%n] <= nums[(i+1)%n]){
10                cnt++;
11                if(cnt == n) return true;
12            }else{
13                cnt = 1;
14            }
15        }
16        return false;
17    }
18};