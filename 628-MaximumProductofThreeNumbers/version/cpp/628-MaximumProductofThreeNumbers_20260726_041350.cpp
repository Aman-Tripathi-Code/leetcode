// Last updated: 7/26/2026, 4:13:50 AM
1class Solution {
2public:
3    int maximumProduct(vector<int>& nums) {
4        int n = nums.size();
5        int largest = INT_MIN, secondLargest = INT_MIN, thirdLargest = INT_MIN;
6        int smallest = INT_MAX, secondSmallest = INT_MAX;
7        for(int i = 0; i<n; i++){
8            if(nums[i] > largest){
9                thirdLargest = secondLargest;
10                secondLargest = largest;
11                largest = nums[i];
12            }else if(nums[i] > secondLargest && nums[i] <= largest){
13                thirdLargest = secondLargest;
14                secondLargest = nums[i];
15            }else if(nums[i] > thirdLargest && nums[i] <= secondLargest){
16                thirdLargest = nums[i];
17            }
18
19            if(nums[i] < smallest){
20                secondSmallest = smallest;
21                smallest = nums[i];
22            }else if(nums[i] < secondSmallest && nums[i] >= smallest){
23                secondSmallest = nums[i];
24            }
25        }
26        return max(largest * secondLargest * thirdLargest, largest * smallest * secondSmallest);
27    }
28};