// Last updated: 7/22/2026, 8:11:19 PM
1class Solution {
2public:
3    static bool cmp(string &a, string &b){
4        string tempa = a + b;
5        string tempb = b + a;
6
7        return tempa > tempb;
8    }
9    string largestNumber(vector<int>& nums) {
10        vector<string> str;
11        for(auto &it:nums){
12            str.push_back(to_string(it));
13        }
14        sort(str.begin(),str.end(),cmp);
15        if(str[0] == "0") return "0";
16        string ans = "";
17        for(auto &s: str){
18            ans += s;
19        }
20        return ans;
21    }
22};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              