// Last updated: 1/11/2026, 1:01:03 PM
class Solution {
private:
    bool isPossible(int rem, unordered_map<int,int> &mp){
        if(rem == 0) return true;
        int req = rem/20;
        
        rem -= 20 * min(req,mp[20]);
        mp[20] -= min(req,mp[20]);
        // cout << rem << " ";
        if(rem == 0) return true;
        
        req = rem/10;
        
        rem -= 10 * min(req,mp[10]);
        mp[10] -= min(req,mp[10]);
                // cout << rem << " ";
        if(rem == 0) return true;
        
        req = rem/5;
        
        rem -= 5 * min(req,mp[5]);
        mp[5] -= min(req,mp[5]);
                // cout << rem << " " << endl;
        if(rem == 0) return true;
        return false;
    }
  public:
    bool lemonadeChange(vector<int> &bills) {
        // code here
        int N = bills.size();
        unordered_map<int,int> mp;
        mp[5] = mp[10] = mp[20] = 0;
        for(int i = 0; i<N; i++){
            int rem = bills[i]-5;
            mp[bills[i]]++;
            if(!isPossible(rem,mp)){
                return false;
            }
        }
        return true;
    }
};