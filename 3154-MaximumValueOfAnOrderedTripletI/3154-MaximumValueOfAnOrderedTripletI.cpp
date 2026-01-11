// Last updated: 1/11/2026, 12:59:25 PM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxi = 0;
        for(int i = 0; i<n-2; i++){
            for(int j = i+1; j<n-1; j++){
                long long diff = (nums[i]-nums[j]);
                for(int k = j+1; k<n; k++){
                    long long temp = diff*nums[k];
                    maxi = max(maxi,temp);
                }
            }
        }
        return maxi;
    }
};