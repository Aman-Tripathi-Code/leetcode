// Last updated: 4/23/2026, 11:19:28 PM
1class Solution {
2public:
3    vector<long long> getDistances(vector<int>& nums) {
4         // map -> int -> num, pair<long long, int> long long -> sum , int num of
5        // num
6        unordered_map<int, pair<long long, long long>> pre, suf;
7        int n = nums.size();
8        vector<long long> ans;
9        for (int i = 0; i < n; i++) {
10            if (suf.find(nums[i]) != suf.end()) {
11                long long sum = suf[nums[i]].first + i;
12                long long freq = suf[nums[i]].second + 1;
13                suf[nums[i]] = {sum, freq};
14            } else {
15                suf[nums[i]] = {i, 1};
16            }
17        }
18        for(long long i = 0; i<n; i++){
19            //left side
20            long long leftSum = 0;
21            if(pre.find(nums[i]) != pre.end()){
22                long long sum = pre[nums[i]].first;
23                long long freq = pre[nums[i]].second ;
24                
25                leftSum = abs(freq* 1LL * i - sum);
26                pre[nums[i]] = {sum + i, freq + 1};
27            }else{
28                pre[nums[i]] = {i, 1};
29            }
30            //right side sum
31            suf[nums[i]].first -= i;
32            suf[nums[i]].second--;
33            long long rightSum = suf[nums[i]].first - suf[nums[i]].second * 1LL * i ;
34
35            ans.push_back(leftSum + rightSum); 
36        }
37        return ans;
38    }
39};