// Last updated: 1/11/2026, 12:59:53 PM
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxi = 0;
        int start = 0, end = 0;
        int n = answerKey.size();
        //flipping false to true
        int cnt = 0;
        while(end < n){
            if(answerKey[end] == 'F'){
                cnt++;
            }
            if(cnt <= k){
                maxi = max(maxi,end-start+1);
            }
            else if(cnt > k){
                while(cnt > k && start < n){
                    if(answerKey[start] == 'F'){
                        cnt--;
                    }
                    start++;
                }
                if(cnt <= k) maxi = max(maxi,end-start+1);
            }
            end++;
        }
        //flipping true to false
        start = 0; end = 0; cnt = 0;
        while(end < n){
            if(answerKey[end] == 'T'){
                cnt++;
            }
            if(cnt <= k){
                maxi = max(maxi,end-start+1);
            }
            if(cnt > k){
                while(cnt > k && start < n){
                    if(answerKey[start] == 'T'){
                        cnt--;
                    }
                    start++;
                }
                if(cnt <= k) maxi = max(maxi,end-start+1);
            }
            end++;
        }
        return maxi;
    }
};