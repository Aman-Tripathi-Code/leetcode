// Last updated: 8/22/2026, 5:33:27 AM
1class Solution {
2public:
3    int findSum(int n){
4        int res = 0;
5        while(n){
6            res += n % 10;
7            n /= 10;
8        }
9        return res;
10    }
11    int findProd(int n){
12        int res = 1;
13        while(n){
14            res *= n % 10;
15            n /= 10;
16        }
17        return res;
18    }
19    bool checkDivisibility(int n) {
20        int sum = findSum(n), prod = findProd(n);
21        return (n % (sum + prod) == 0);
22    }
23};