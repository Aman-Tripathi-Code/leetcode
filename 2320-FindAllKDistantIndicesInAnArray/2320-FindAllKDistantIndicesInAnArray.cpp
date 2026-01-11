// Last updated: 1/11/2026, 12:59:46 PM
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> arr;
        for(int i = 0; i<nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(nums[j]==key){
                    if(abs(i-j)<=k){
                        arr.push_back(i);
                    }
                }
            }
        }
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        return arr;
    }
};