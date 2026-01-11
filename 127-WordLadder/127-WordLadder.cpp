// Last updated: 1/11/2026, 1:03:01 PM
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        queue<pair<int,string>> q;
        q.push({1,beginWord});
        unordered_map<string,int> mp;
        for(auto it:wordList){
            mp[it] = 1e9;
        }
        if(mp.find(endWord)==mp.end()){
            return 0;
        }
        mp[beginWord] = 1;
        while(!q.empty()){
            int currStep = q.front().first;
            string str = q.front().second;
            mp.erase(str);
            q.pop();
            for(int j = 0; j<str.size(); j++){
                char og = str[j];
                for(int i = 0; i<26;i++){
                    str[j] = 'a'+ i;

                    if(mp.find(str)!=mp.end()){
                        if(mp[str]>currStep+1){
                            q.push({currStep+1,str});
                            mp[str] = currStep+1;
                            if(str==endWord){
                                return currStep+1;
                            }
                        }
                    }
                }
                str[j] = og;
            }
        }
        return 0;
    }
};