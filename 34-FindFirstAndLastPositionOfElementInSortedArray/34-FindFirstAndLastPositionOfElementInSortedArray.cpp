// Last updated: 1/11/2026, 1:04:00 PM
class Solution {
public:
    int __lowerbound(vector<int>&v, int x){
        int lo = -1, hi = v.size();
        while(lo<hi-1){
            int mid = (lo+hi)>>1;
            if(v[mid]<=x){
                lo = mid;
            }
            else hi = mid;
        }
        return lo;
    }

    int __upperbound(vector<int>&v, int x){
        int lo = -1, hi = v.size();
        while(lo<hi-1){
            int mid = (lo+hi)>>1;
            if(v[mid]<x){
                lo = mid;
            }
            else hi = mid;
        }
        return hi;
    }
    bool __binarySearch(vector<int>&v, int x){
        int lo = 0, hi = v.size()-1;
        while(lo<=hi){
            int mid = (lo+hi)>>1;
            if(v[mid]==x){
                return true;
            }
            else if(v[mid]<x){
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return false;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(!__binarySearch(nums,target)){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int start = __upperbound(nums,target);
        int end = __lowerbound(nums,target);
        // cout << start << " " << end << endl;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};