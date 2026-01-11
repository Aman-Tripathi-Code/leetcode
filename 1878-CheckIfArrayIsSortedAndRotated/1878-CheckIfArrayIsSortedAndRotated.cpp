// Last updated: 1/11/2026, 12:59:59 PM
class Solution {
public:
    bool check(vector<int>& nums) {
        int len = nums.size();
        int count = 1;
        for(int i = 0; i<2*len; i++){
            if(count == len){
                break;
            }
            if(nums[i%len]<=nums[(i+1)%len]){
                count++;
            }
            else count = 1;
        }
        return count==len;
    }
};