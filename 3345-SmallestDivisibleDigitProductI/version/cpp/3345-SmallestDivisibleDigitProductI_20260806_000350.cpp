// Last updated: 8/6/2026, 12:03:50 AM
1class Solution {
2public:
3    int productOfDigit(int n){
4        int res = 1;
5        while(n){
6            res *= (n % 10);
7            n /= 10;
8        }
9        return res;
10    }
11    int smallestNumber(int n, int t) {
12        for(int i = n; i<=100; i++){
13            if(productOfDigit(i) % t == 0){
14                return i;
15            }
16        }
17        return 100;
18    }
19};