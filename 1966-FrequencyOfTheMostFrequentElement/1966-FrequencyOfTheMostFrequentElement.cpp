// Last updated: 1/11/2026, 12:59:58 PM
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long n = nums.size(),i = 0, j = 0,maxi = 0;
        long long int sum = 0;
        while(j<n){
            sum += nums[j];
            while((nums[j] * (j-i+1) - sum ) > k){
                sum -= nums[i];
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};