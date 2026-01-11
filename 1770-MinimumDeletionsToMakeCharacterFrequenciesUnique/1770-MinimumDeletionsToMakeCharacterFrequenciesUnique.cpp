// Last updated: 1/11/2026, 1:00:01 PM
class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        map<char,int> mp;
        for(int i = 0; i<n; i++){
            mp[s[i]]++;
        }
        set<int> st;
        int ans = 0;
        for(auto it:mp){
            if(st.find(it.second) == st.end()){
                st.insert(it.second);
            }
            else{
                int temp = it.second;
                while(st.find(temp) != st.end()){
                    temp--;
                }
                ans += it.second - temp;
                if(temp != 0) st.insert(temp);
            }
        }
        return ans;
    }
};