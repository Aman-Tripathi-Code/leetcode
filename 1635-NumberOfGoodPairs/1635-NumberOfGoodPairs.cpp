// Last updated: 1/11/2026, 1:00:10 PM
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(101,0);
        int res = 0;
        for(int i = 0; i<n; i++){
            res += freq[nums[i]]++; 
        }
        return res;
    }
};