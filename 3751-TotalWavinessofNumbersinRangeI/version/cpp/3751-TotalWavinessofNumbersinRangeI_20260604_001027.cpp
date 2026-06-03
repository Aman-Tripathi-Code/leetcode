// Last updated: 6/4/2026, 12:10:27 AM
1class Solution {
2public:
3    int findWaviness(int n){
4        string s = to_string(n);
5        int len = s.length(), cnt = 0;
6        if(len < 3) return 0;
7        for(int i = 1; i<len-1; i++){
8            if((s[i] > s[i-1] && s[i] > s[i+1]) || (s[i] < s[i-1] && s[i] < s[i+1])){
9                cnt++;
10            } 
11        }
12        return cnt;
13    }
14    int totalWaviness(int num1, int num2) {
15        int waviness = 0;
16        for(int i = num1; i<=num2; i++){
17            waviness += findWaviness(i);
18        }
19        return waviness;
20    }
21};
22
23