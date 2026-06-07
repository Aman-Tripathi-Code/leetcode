// Last updated: 6/8/2026, 2:08:22 AM
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long m = mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i = 0; i<n; i++){
            if(m >= asteroids[i]){
                m += asteroids[i];
            }else{
                return false;
            }
        }
        return true;
    }
};