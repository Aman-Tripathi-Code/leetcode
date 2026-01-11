// Last updated: 1/11/2026, 1:01:42 PM
class Solution {
private:
    int merge(vector<int>& nums, int lo, int mid, int hi){

        int cnt  = 0;

        int j = mid + 1;

        for(int i = lo; i<=mid; i++){
            while(j <= hi && nums[i] > (long long)2*nums[j]){
                j++;
            }
            cnt += (j-(mid+1));
        }



        vector<int> temp;
        int i = lo;
        j = mid+1;
        while(i <= mid && j <= hi){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= hi){
            temp.push_back(nums[j]);
            j++;
        }

        for(int k = lo; k<=hi; k++){
            nums[k] = temp[k-lo];
        }
        return cnt;
    }

    int mergeSort(vector<int>& nums, int lo, int hi){
        int cnt = 0;
        if(lo >= hi) return 0;
        int mid = (lo + hi) / 2;
        
        cnt += mergeSort(nums,lo,mid);
        cnt += mergeSort(nums,mid+1,hi);

        cnt += merge(nums,lo,mid,hi);

        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums,0,n-1);
    }
};