// Last updated: 5/27/2026, 2:20:33 PM
1class Solution {
2public:
3    int sumOfDigits(int n){
4        int sum = 0;
5        while(n){
6            sum += n % 10;
7            n /= 10;
8        }
9        return sum;
10    }
11    int countBalls(int lowLimit, int highLimit) {
12        vector<int> hs(46,0);
13        for(int i = lowLimit; i<=highLimit; i++){
14            int sum = sumOfDigits(i);
15            hs[sum]++;
16        }
17        return *max_element(hs.begin(),hs.end());
18    }
19};