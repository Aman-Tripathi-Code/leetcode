// Last updated: 1/11/2026, 1:00:49 PM
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i = 0, j = n-1, ind = n-1;
        while(i<=j){
            if(abs(nums[i])>abs(nums[j])){
                ans[ind] = nums[i]*nums[i];
                i++;
            }
            else{
                ans[ind] = nums[j]*nums[j];
                j--;
            }
            ind--;
        }
        return ans;
    }
};