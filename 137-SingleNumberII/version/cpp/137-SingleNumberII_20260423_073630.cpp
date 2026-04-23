// Last updated: 4/23/2026, 7:36:30 AM
1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        vector<int> bits(32);
5        for(int i = 0; i<nums.size(); i++){
6            for(int j = 0; j<32; j++){
7                int bit = (nums[i] & (1<<j));
8                if(bit) bits[j]++;
9            }
10        }
11        int res = 0;
12        for(int i = 0; i<32; i++){
13            if(bits[i] % 3){
14                res += (1<<i);
15            }
16        }
17        return res;
18    }
19};