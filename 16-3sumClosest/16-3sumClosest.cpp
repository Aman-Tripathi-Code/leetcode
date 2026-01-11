// Last updated: 1/11/2026, 1:04:10 PM
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        sort(nums.begin(),nums.end());

        for(int i = 0; i<n-2; i++){
            int j = i+1, k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==target){
                    return target;
                }
                else if(sum<target){
                    j++;
                }
                else if(sum>target){
                    k--;
                }
                pq.push({abs(target-sum),sum});
            }

        }
        return pq.top().second;
    }
};