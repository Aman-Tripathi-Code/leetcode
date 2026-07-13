// Last updated: 7/14/2026, 2:39:34 AM
1class Solution {
2public:
3    void createSeqDigit(int num, int low, int high, vector<int>& ans){
4        int res = num;
5        for(int i = num+1; i<=9; i++){
6            if((res > (INT_MAX/10)) || (res == (INT_MAX/10) && i > INT_MAX%10)){
7                break;
8            }
9            res = res * 10 + i;
10            if(res >= low && res <= high){
11                ans.push_back(res);
12            }else if(res > high){
13                break;
14            }
15        }
16
17    }
18    vector<int> sequentialDigits(int low, int high) {
19        vector<int> ans;
20        for(int i = 1; i<=9; i++){
21            createSeqDigit(i,low,high,ans);
22        }
23        sort(ans.begin(),ans.end());
24        return ans;
25    }
26};