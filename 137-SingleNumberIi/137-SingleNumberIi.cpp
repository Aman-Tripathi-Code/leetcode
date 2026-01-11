// Last updated: 1/11/2026, 1:02:54 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32);
        for(int i = 0; i<nums.size(); i++){
            for(int j = 0; j<32; j++){
                int bit = (nums[i] & (1<<j));
                if(bit) bits[j]++;
            }
        }
        int res = 0;
        for(int i = 0; i<32; i++){
            if(bits[i] % 3){
                res += (1<<i);
            }
        }
        return res;
    }
};