// Last updated: 1/11/2026, 1:01:04 PM
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size(), m = goal.size();
        if(n != m) return false;
        int count = 0;
        unordered_set<char> st;
        int ind1 = -1, ind2 = -1;
        for(int i = 0; i<n; i++){
            st.insert(s[i]);
            if(s[i] != goal[i] && count < 2){
                count++;
                (ind1 == -1) ? ind1 = i : ind2 = i;
            }
        }
        if(count == 2 || count == 0){
            if(count == 2) {
                swap(s[ind1],s[ind2]);
                if(s == goal) return true;
                return false;
            }
            else{
                if(st.size() < n) return true;
                else return false;
            }
        }
        return false;  
    }
};