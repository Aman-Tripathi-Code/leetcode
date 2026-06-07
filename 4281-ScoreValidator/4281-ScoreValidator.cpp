// Last updated: 6/8/2026, 2:07:21 AM
class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0, n = events.size();
        for(int i = 0; i<n; i++){
            if(counter == 10){
                return {score,counter};
            }else{
                if(events[i] == "W"){
                    counter++;
                }else{
                    if(events[i] == "WD" || events[i] == "NB"){
                        score++;
                    }else{
                        score += events[i][0] - '0';
                    }
                }
            }
        }
        return {score,counter};
    }
};