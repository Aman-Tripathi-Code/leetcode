// Last updated: 1/11/2026, 1:02:40 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, cand = nums[0];
        int sz = nums.size();
        for(int i = 0; i<sz; i++){
            if(cnt == 0){
               cand = nums[i]; 
            }
            if(nums[i]==cand){
                cnt++;
            }
            else cnt--;
        }
        return cand;
    }
};