// Last updated: 1/11/2026, 1:00:32 PM
const int N = 1e5+1;
int divCnt[N];
int divSum[N];

int init = []{
    for(int i = 1; i < N; i++){
        for(int j = i; j < N ; j += i){
            divCnt[j]++;
            divSum[j] += i;
        }
    }
    return 0;
}();



class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto &x: nums){
            if(divCnt[x] == 4){
                ans += divSum[x];
            }
        }
        return ans;
    }
};