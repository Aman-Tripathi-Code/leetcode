// Last updated: 7/26/2026, 3:13:49 AM
1class Solution {
2public:
3    int maxProduct(int n) {
4        int largest = -1, secondLargest = -1;
5        while(n){
6            int digit = n % 10;
7            if(digit > largest){
8                secondLargest = largest;
9                largest = digit;
10            }else if(digit > secondLargest && digit <= largest){
11                secondLargest = digit;
12            }
13            n /= 10;
14        }
15        return largest * secondLargest;
16    }
17};