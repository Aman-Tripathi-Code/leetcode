// Last updated: 7/6/2026, 10:59:58 PM
1class Solution {
2    long reverseInt(long n){
3        long rev = 0;
4        while(n>0){
5            rev = 10 * rev + n % 10;
6            n /= 10;
7        }
8        return rev;
9    }
10    public long sumAndMultiply(int n) {
11        long num = 0;
12        int sum = 0;
13        while(n>0){
14            int rem = n % 10;
15            if(rem > 0){
16                num = (long)(10*num + rem);
17                sum += rem;
18            }
19            n /= 10;
20        }
21        num = reverseInt(num);
22        return (long)(num * sum);
23    }
24}