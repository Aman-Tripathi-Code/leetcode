// Last updated: 1/11/2026, 1:04:18 PM
class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n1 = arr1.size(), n2 = arr2.size();
    if(n2 < n1) return findMedianSortedArrays(arr2,arr1);
    double ans = 0;
    int lo = 0, hi = n1;
    
    while(lo <= hi){
        int cut1 = lo + (hi-lo)/2;
        int cut2 = (n1 + n2 + 1)/2 - cut1;
        
        int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1-1];
        int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2-1]; 
        
        int right1 = (cut1 == n1) ? INT_MAX : arr1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : arr2[cut2];
        
        if(left1 <= right2 && left2 <=  right1){
            if((n1 + n2) & 1){
                ans =  max(left1,left2);
                return ans;
            }
            else{
                ans = (max(left1,left2) + min(right1,right2))/2.0;
                return ans;
            }
        }
        else if(left1 > right2){
            hi = cut1 - 1;
        }
        else{
            lo = cut1 + 1;
        }
    }
    return 0.0;
    }
};