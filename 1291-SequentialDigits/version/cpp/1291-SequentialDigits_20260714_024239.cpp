// Last updated: 7/14/2026, 2:42:39 AM
1class Solution {
2public:
3    void createSeqDigit(int num, int low, int high, vector<int>& ans){
4        int res = num;
5        for(int i = num+1; i<=9; i++){
6            res = res * 10 + i;
7            if(res >= low && res <= high){
8                ans.push_back(res);
9            }else if(res > high){
10                break;
11            }
12        }
13
14    }
15    vector<int> sequentialDigits(int low, int high) {
16        vector<int> ans;
17        for(int i = 1; i<=9; i++){
18            createSeqDigit(i,low,high,ans);
19        }
20        sort(ans.begin(),ans.end());
21        return ans;
22    }
23};