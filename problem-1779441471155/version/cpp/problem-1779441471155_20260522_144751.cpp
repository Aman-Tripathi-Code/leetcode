// Last updated: 5/22/2026, 2:47:51 PM
1class Solution {
2public:
3    vector<int> size, par;
4    int findPar(int node) {
5        if (node == par[node]) {
6            return node;
7        }
8        return par[node] = findPar(par[node]);
9    }
10    void unionBySize(int x, int y) {
11        int xPar = findPar(x), yPar = findPar(y);
12        if (xPar == yPar)
13            return;
14        if (size[xPar] > size[yPar]) {
15            par[yPar] = xPar;
16        } else if (size[yPar] > size[xPar]) {
17            par[xPar] = yPar;
18        } else {
19            par[yPar] = xPar;
20            size[xPar]++;
21        }
22    }
23    int minimumHammingDistance(vector<int>& source, vector<int>& target,
24                               vector<vector<int>>& allowedSwaps) {
25        int n = source.size();
26        par.assign(n, 0);
27        size.assign(n, 0);
28        for (int i = 0; i < n; i++) {
29            par[i] = i;
30            size[i] = 1;
31        }
32        unordered_map<int,unordered_set<int>> mp;
33        int cnt = 0;
34        for(int i = 0; i<n; i++){
35            mp[target[i]].insert(i);
36        }
37
38        for(auto &it : allowedSwaps){
39            if(findPar(it[0]) != findPar(it[1])){
40                unionBySize(it[0],it[1]);
41            }
42        }
43
44        for(int i = 0; i<n; i++){
45            if(mp.find(source[i]) == mp.end()){
46                // cout << source[i] << ' ' << "is not present in the target so increasing the cnt ";
47                cnt++;
48                // cout <<  cnt << endl;
49                continue;
50            }
51            if(mp[source[i]].find(i) != mp[source[i]].end()){
52                // cout << source[i] << ' ' << "is present in the target at the same index so not increasing the cnt " << cnt << endl;
53                mp[source[i]].erase(i);
54                continue;
55            }else{
56                bool found = false;
57                for(auto &it: mp[source[i]]){
58                    if(findPar(i) == findPar(it)){
59                        
60                    // cout << source[i] << ' ' << "is present in the target so not increasing the cnt ";
61                    //     cout << source[i] << " is at index " << i << " in the source array and in the target array it will get swapped to " << it << " where the target node is " << target[it] << " and the parent of both the index is " << par[it] << endl;
62                        mp[source[i]].erase(it);
63                        found = true;
64                        break;
65                    }
66                }
67                if(!found) {
68                    // cout << source[i] << ' ' << "no index is present to swap for this so increasing the cnt ";
69
70                    cnt++;
71                    // cout << cnt << endl;
72                }
73            }
74        }
75        return cnt;
76    }
77};