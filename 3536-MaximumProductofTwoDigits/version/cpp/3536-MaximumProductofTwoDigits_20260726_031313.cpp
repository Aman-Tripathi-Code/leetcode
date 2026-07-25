// Last updated: 7/26/2026, 3:13:13 AM
1class Solution {
2public:
3    int maxProduct(int n) {
4        int largest = -1, secondLargest = -1;
5        while(n){
6            int digit = n % 10;
7            cout << n << ' ' << digit << ' ' << largest << ' ' << secondLargest << endl;
8            if(digit > largest){
9                secondLargest = largest;
10                largest = digit;
11            }else if(digit > secondLargest && digit <= largest){
12                secondLargest = digit;
13            }
14            cout << largest << ' ' << secondLargest << endl;
15            n /= 10;
16        }
17        return largest * secondLargest;
18    }
19};