// Last updated: 6/8/2026, 2:07:31 AM
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), maxi = 0;
        unordered_set<int> odd, even;
        for(int i = 0; i<n-1; i++){
            if(nums[i] & 1) odd.insert(nums[i]);
            else even.insert(nums[i]);
            for(int j = i+1; j<n; j++){
                if(nums[j] & 1) odd.insert(nums[j]);
                else even.insert(nums[j]);
                if(odd.size() == even.size()){
                    maxi = max(maxi, (j-i+1));
                }
            }
            odd.clear();
            even.clear();
        }
        return maxi;
    }
};