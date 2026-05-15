// Last updated: 5/15/2026, 2:30:21 PM
1class Solution {
2public:
3    string interpret(string command) {
4        int n = command.size();
5        string s;
6        for (int i = 0; i < n; i++) {
7            if (command[i] == 'G') {
8                s.push_back('G');
9            } else if (command[i] == '(') {
10                if (command[i + 1] == ')') {
11                    s.push_back('o');
12                } else {
13                    s.push_back('a');
14                    s.push_back('l');
15                }
16            }
17        }
18        return s;
19    }
20};