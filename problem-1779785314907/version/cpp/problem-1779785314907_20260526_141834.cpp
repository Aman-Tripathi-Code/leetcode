// Last updated: 5/26/2026, 2:18:34 PM
1class Solution {
2public:
3    string maximumTime(string time) {
4        int n = time.size();
5        for(int i = 0; i<n; i++){
6            if(time[i] == '?'){
7                if(i == 0) time[i] = (time[1] != '?' && time[1] > '3') ? '1' : '2';
8                if(i == 1) time[i]= (time[0] == '2') ? '3' : '9';
9                if(i == 3) time[i] = '5';
10                if(i == 4) time[i] = '9';
11            }
12        }
13        return time;
14    }
15};