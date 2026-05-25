// Last updated: 5/25/2026, 1:48:15 PM
1class Solution {
2public:
3    int countGoodRectangles(vector<vector<int>>& rectangles) {
4        int maxLen = 0, cnt = 0;
5        for(auto &it : rectangles){
6            int miniSide = min(it[0],it[1]);
7            if(miniSide > maxLen){
8                maxLen = miniSide;
9                cnt = 1;
10            }else if(miniSide == maxLen){
11                cnt++;
12            }
13        }
14        return cnt;
15    }
16};