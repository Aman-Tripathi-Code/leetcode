// Last updated: 6/8/2026, 2:08:33 AM
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> conCat;
        for(int i = 0; i<2*n; i++){
            conCat.push_back(nums[i%n]);
        }
        return conCat;
    }
};