// Last updated: 1/11/2026, 1:04:06 PM
class Solution {
public:
    vector<string> str;
    void generate( string &s, int o , int p){
        if(o==0&&p==0){
            str.push_back(s);
            return;
        }
        if(o>0){
            s.push_back('(');
            generate(s,o-1,p);
            s.pop_back();
        }
        if(p>0&&o<p){
            s.push_back(')');
            generate(s,o,p-1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        generate(s,n,n);
        return str;
        }
};