// Last updated: 1/11/2026, 1:04:09 PM
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i<n ; i++){
            long long int remTarget1 = target-nums[i];
            for(int j = i+1; j<n ; j++){
                int start = j+1, end = n-1;
                long long int remTarget = remTarget1-nums[j];
                while(start<end){
                    if((nums[start]+nums[end])<remTarget){
                        ++start;
                    }
                    else if((nums[start]+nums[end])>remTarget){
                        --end;
                    }
                    else{
                        vector<int> ds(4);
                        ds[0] = nums[i];
                        ds[1] = nums[j];
                        ds[2] = nums[start];
                        ds[3] = nums[end];
                        ans.push_back(ds);
                        while(start<end && nums[start]==ds[2]) start++;
                        while(start<end && nums[end]==ds[3]) end--;
                    }
                    while(j<n-1 && nums[j]==nums[j+1]) j++;
                }
                while(i<n-1 && nums[i]==nums[i+1]) i++;
            }
        }
        return ans;
    }
};