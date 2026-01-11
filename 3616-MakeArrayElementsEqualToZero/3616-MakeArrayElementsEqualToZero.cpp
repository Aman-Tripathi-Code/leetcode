// Last updated: 1/11/2026, 12:59:15 PM
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int currSum = 0, count = 0,n = nums.size();

        for(int i = 0; i<n; i++){
            currSum += nums[i];
            if(nums[i] == 0){
                if(currSum == (sum - currSum)){
                    count += 2;
                }
                if(abs(sum - (2 * currSum)) == 1){
                    count += 1;
                }
            }
        }
        return count;
    }
};