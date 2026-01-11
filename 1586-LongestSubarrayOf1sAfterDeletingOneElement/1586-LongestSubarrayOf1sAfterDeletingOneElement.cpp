// Last updated: 1/11/2026, 1:00:16 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), maxi = 0;
        int count = 1, i = 0;
        for(int j = 0; j<n; j++){
            if(nums[j] == 0){
                count--;
            }
            if(count < 0){
                while(count < 0){
                    if(nums[i] == 0){
                        count++;
                    }
                    i++;
                }
            }
            maxi = max(maxi,j-i);
        }
        return maxi;
    }
};