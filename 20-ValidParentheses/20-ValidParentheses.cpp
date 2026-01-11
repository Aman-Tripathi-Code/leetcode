// Last updated: 1/11/2026, 1:04:07 PM
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int sz = s.size();
        for(int i =0; i<sz ; i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
               st.push(s[i]);
            } 
            else{
                if(st.empty()){
                    return false;
                }
                else if((s[i]==')'&&st.top()=='(')||(s[i]==']'&&st.top()=='[')||(s[i]=='}'&&st.top()=='{')){
                    st.pop();
                }
                else return false;
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};