// Last updated: 1/11/2026, 1:04:11 PM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n-2; i++){
            int j = i+1, k = n-1;
            while(j<k){
                vector<int> ds;
                int sum = nums[j] + nums[k] + nums[i];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else if(sum == 0){
                    ds.push_back(nums[i]);
                    ds.push_back(nums[j]);
                    ds.push_back(nums[k]);
                    while(j<n-1 && nums[j]==nums[j+1]) j++;
                    while(k>0 && nums[k]==nums[k-1]) k--;
                    j++; k--;
                    ans.push_back(ds);
                }
            }
            while(i<n-1 && nums[i]==nums[i+1])i++;
        }
        return ans;
    }
};