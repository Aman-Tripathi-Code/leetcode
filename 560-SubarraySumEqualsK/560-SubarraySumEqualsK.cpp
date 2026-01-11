// Last updated: 1/11/2026, 1:01:30 PM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size(), maxi = 0, sum = 0;
        mp[sum] = 1;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            maxi += mp[sum-k];
            mp[sum]++;
            
        }
        return maxi;
    }
};