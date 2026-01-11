// Last updated: 1/11/2026, 1:03:32 PM
class Solution {
private:
    //brute
    void brute(vector<int> &nums){
        sort(nums.begin(), nums.end());
    }
    //count sort
    void countColor(vector<int> &nums){
        int zeroCount = 0, oneCount = 0, twoCount = 0;
        for(int i= 0; i<nums.size(); i++){
            if(nums[i]==0){
                zeroCount++;
            }
            else if(nums[i]==1){
                oneCount++;
            }
            else twoCount++;
        }
        for(int i = 0; i<zeroCount ; i++){
            nums[i] = 0;
        }
        for(int i = 0; i<oneCount; i++){
            nums[i+zeroCount] = 1;
        }
        for(int i = 0; i<twoCount ; i++){
            nums[i+zeroCount+oneCount] = 2;
        }
    }
public:
    void sortColors(vector<int>& nums) {
        //Dutch flag algorithms
        int lo = 0, mid = 0 , hi = nums.size()-1;
        while(hi>=mid){
            if(nums[mid]==0){
                swap(nums[mid],nums[lo]);
                lo++;
                mid++;
            }
            else if (nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[hi]);
                hi--;
            }
        }
    }
};