// Last updated: 5/11/2026, 10:52:09 PM
1class Solution {
2public:
3    static bool cmp(pair<string, int>& a, pair<string, int>& b) {
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
21        while (!q.empty()) {
22            int sz = q.size();
23            for (int i = 0; i < sz; i++) {
24                int node = q.front();
25                q.pop();
26
27                for (auto& it : friends[node]) {
28                    if (!vis[it]) {
29                        q.push(it);
30                        vis[it] = 1;
31                    }
32                }
33            }
34            currLvl++;
35
36            if (currLvl == level) {
37                while (!q.empty()) {
38                    int frnd = q.front();
39                    q.pop();
40
41                    friendAtLevel.push_back(frnd);
42                }
43                break;
44            }
45        }
46
47        map<string, int> mp;
48
49        for (auto& frnd : friendAtLevel) {
50            for (auto& video : watchedVideos[frnd]) {
51                mp[video]++;
52            }
53        }
54
55        vector<pair<string, int>> mapArray(mp.begin(), mp.end());
56
57        sort(mapArray.begin(), mapArray.end(), cmp);
58
59        vector<string> ans;
60
61        for (auto& it : mapArray) {
62            ans.push_back(it.first);
63        }
64
65        return ans;
66    }
67};