// Last updated: 1/11/2026, 12:59:47 PM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for(int i= 0; i<nums.size(); i++){
            if(nums[i] < 0){
                neg.push_back(nums[i]);
            }
            else pos.push_back(nums[i]);
        }
        int i = 0, j = 0;
        while(i<nums.size()){
            nums[i++] = pos[j];
            nums[i++] = neg[j];
            j++; 
        }
        return nums;
    }
};