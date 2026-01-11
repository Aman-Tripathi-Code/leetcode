// Last updated: 1/11/2026, 1:04:21 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hs;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(hs.find(target-nums[i])!=hs.end()){
                ans.push_back(i);
                ans.push_back(hs[target-nums[i]]);
                break;
            }
            else{
                hs[nums[i]] = i;
            }
        }
        return ans;
    }
};