// Last updated: 1/11/2026, 1:00:18 PM
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int oneInd = -1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                if(oneInd != -1){
                    if((i - oneInd -1) < k){
                        return false;
                    }
                }
                oneInd = i;
            }
        }
        return true;
    }
};