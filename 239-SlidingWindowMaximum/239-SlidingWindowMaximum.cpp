// Last updated: 1/11/2026, 1:02:11 PM
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int i = 0, j = 0;
        deque<int> dq;
        int n = nums.size();
        while(j<n){
            while(!dq.empty()&&nums[j]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if(j-i+1==k){
                ans.push_back(dq.front());
                if(nums[i]==dq.front()){
                    dq.pop_front();
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};