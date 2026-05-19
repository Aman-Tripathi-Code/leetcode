// Last updated: 5/19/2026, 2:47:00 PM
1class Solution {
2public:
3    string removeDashes(string& number){
4        string s;
5        for(int i = 0; i<number.length(); i++){
6            if(number[i] >= '0' && number[i] <= '9'){
7                s.push_back(number[i]);
8            }
9        }
10        return s;
11    }
12    string reformatNumber(string number) {
13        number = removeDashes(number);
14        int len = number.size();
15        if(len <= 3) return number;
16        string ans;
17        for(int i = 0; i<len; i++){
18            if(i != 0 && i % 3 == 0){
19                ans.push_back('-');   
20            }
21            ans.push_back(number[i]);
22        }
23        if(len % 3 == 1){
24            int l = ans.size();
25            swap(ans[l-2],ans[l-3]);
26        }
27        return ans;
28    }
29};