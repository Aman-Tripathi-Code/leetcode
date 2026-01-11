// Last updated: 1/11/2026, 1:02:28 PM
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int maxi = 1e9, sum = 0;
        int i = 0, j = 0;
        while(j < n){
            sum += nums[j];
            if(sum == target){
                maxi = min(j-i+1,maxi);
            }
            if(sum > target){
                while(sum > target){
                    maxi = min(j-i+1,maxi);
                    sum -= nums[i];
                    i++;
                }
                if(sum == target){
                    maxi = min(j-i+1,maxi);
                }
            }
            j++;
        }
        return (maxi == 1e9) ? 0 : maxi;
    }
};