// Last updated: 6/8/2026, 2:07:37 AM
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        bool flag = false;
        if(nums[0] >= nums[1]) return false;
        for(int i = 1; i<n-1; i++){
            if(nums[i] == nums[i+1]) return false;
            if(!flag){
                if(nums[i] > nums[i+1]){
                    flag = !flag;
                    cnt++;
                    // cout <<  flag << ' ' << i << endl;
                }
            }else{
                if(nums[i] < nums[i+1]){
                    flag = !flag;
                    cnt++;
                    // cout <<  flag << ' ' << i << endl;

                }
            }
        }
        // cout << cnt << endl;
        return cnt == 2;
    }
};