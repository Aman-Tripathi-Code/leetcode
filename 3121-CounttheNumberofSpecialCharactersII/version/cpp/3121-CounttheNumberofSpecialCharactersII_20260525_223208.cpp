// Last updated: 5/25/2026, 10:32:08 PM
class Solution {
public:
    #define pii pair<int,int>
    #define pb push_back
    #define ll long long
    #define f first
    #define s second
    int numberOfSpecialChars(string word) {
        vector<pii>vec(26,{INT_MIN,INT_MAX});
        int n=word.length();
        for(int i=0;i<n;i++){
            char c=word[i];
            if(islower(c)){
                vec[c-'a'].f=max(vec[c-'a'].f,i);
            }else{
                vec[c-'A'].s=min(vec[c-'A'].s,i);
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(vec[i].f!=INT_MIN && vec[i].s!=INT_MAX &&  vec[i].f<vec[i].s) ans++;
        }
        return ans;
    }
};