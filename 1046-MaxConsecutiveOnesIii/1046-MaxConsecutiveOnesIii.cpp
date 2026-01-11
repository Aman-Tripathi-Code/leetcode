// Last updated: 1/11/2026, 1:00:45 PM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int maxi = -1e9;
        while(j < n){
            if(nums[j] == 0){
                k--;
            }
            if(k >= 0){
                maxi = max(maxi,j-i+1);
            }
            else{
                while(k<0){
                    if(nums[i] == 0){
                        k++;
                    }
                    i++;
                }
                maxi = max(maxi,j-i+1);
            }
            j++;
        }
        return maxi;
    }
};