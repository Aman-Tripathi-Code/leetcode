// Last updated: 5/20/2026, 2:49:35 PM
1class Solution {
2public:
3    int eatenApples(vector<int>& apples, vector<int>& days) {
4        int n = apples.size();
5        int cnt = 0;
6        priority_queue<pair<int, int>, vector<pair<int, int>>,
7                       greater<pair<int, int>>>
8            pq; // lastDay, no. of apple
9        for (int i = 0; i < n; i++) {
10            if (apples[i] > 0)
11                pq.push({days[i] + i, apples[i]});
12            bool eaten = false;
13            while (!pq.empty() && !eaten) {
14                auto [lastDay, appleCnt] = pq.top();
15                pq.pop();
16
17                if (lastDay <= i || appleCnt == 0) {
18                    continue;
19                }
20
21                else {
22                    appleCnt -= 1;
23                    pq.push({lastDay, appleCnt});
24                    eaten = true;
25                    cnt++;
26                }
27            }
28        }
29        int curr = n;
30        while (!pq.empty()) {
31            auto [lastDay, apple] = pq.top();
32            pq.pop();
33
34            if (lastDay <= curr || apple == 0)
35                continue;
36            else {
37                apple -= 1;
38                pq.push({lastDay, apple});
39                cnt++;
40            }
41            curr++;
42        }
43        return cnt;
44    }
45};