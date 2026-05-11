// Last updated: 5/11/2026, 10:56:43 PM
1class Solution {
2public:
3    static bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
4        if (a.second == b.second) {
5            return a.first < b.first;
6        }
7        return a.second < b.second;
8    }
9
10    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
11                                          vector<vector<int>>& friends, int id,
12                                          int level) {
13        int n = friends.size();
14
15        queue<int> q;
16        q.push(id);
17        int currLvl = 0;
18        vector<int> friendAtLevel;
19        vector<int> vis(n, 0);
20        vis[id] = 1;
21        unordered_map<string, int> mp;
22        while (!q.empty()) {
23            int sz = q.size();
24            for (int i = 0; i < sz; i++) {
25                int node = q.front();
26                q.pop();
27
28                for (auto& it : friends[node]) {
29                    if (!vis[it]) {
30                        q.push(it);
31                        vis[it] = 1;
32                    }
33                }
34            }
35            currLvl++;
36
37            if (currLvl == level) {
38                while (!q.empty()) {
39                    int frnd = q.front();
40                    q.pop();
41
42                    for (auto& video : watchedVideos[frnd]) {
43                        mp[video]++;
44                    }
45                }
46                break;
47            }
48        }
49
50        vector<pair<string, int>> mapArray(mp.begin(), mp.end());
51
52        sort(mapArray.begin(), mapArray.end(), cmp);
53
54        vector<string> ans;
55
56        for (auto& it : mapArray) {
57            ans.push_back(it.first);
58        }
59
60        return ans;
61    }
62};