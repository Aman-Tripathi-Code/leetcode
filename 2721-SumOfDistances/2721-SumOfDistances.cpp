// Last updated: 6/8/2026, 2:08:05 AM
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        // map -> int -> num, pair<long long, int> long long -> sum , int num of
        // num
        unordered_map<int, pair<long long, long long>> pre, suf;
        int n = nums.size();
        vector<long long> ans;
        for (int i = 0; i < n; i++) {
            if (suf.find(nums[i]) != suf.end()) {
                long long sum = suf[nums[i]].first + i;
                long long freq = suf[nums[i]].second + 1;
                suf[nums[i]] = {sum, freq};
            } else {
                suf[nums[i]] = {i, 1};
            }
        }
        for(long long i = 0; i<n; i++){
            //left side
            long long leftSum = 0;
            if(pre.find(nums[i]) != pre.end()){
                long long sum = pre[nums[i]].first;
                long long freq = pre[nums[i]].second ;
                
                leftSum = abs(freq* 1LL * i - sum);
                pre[nums[i]] = {sum + i, freq + 1};
            }else{
                pre[nums[i]] = {i, 1};
            }
            //right side sum
            suf[nums[i]].first -= i;
            suf[nums[i]].second--;
            long long rightSum = suf[nums[i]].first - suf[nums[i]].second * 1LL * i ;

            ans.push_back(leftSum + rightSum); 
        }
        return ans;
    }
};