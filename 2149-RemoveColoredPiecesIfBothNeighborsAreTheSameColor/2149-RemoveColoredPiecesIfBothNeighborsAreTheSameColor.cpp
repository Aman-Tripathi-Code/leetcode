// Last updated: 1/11/2026, 12:59:52 PM
class Solution {
public:
    bool winnerOfGame(string colors) {
        int count1 = 0, count2 = 0;
        int curr1 = 0, curr2 = 0;
        for(auto it:colors){
            if(it == 'A'){
                curr1++;
                count2 += max(0,curr2 - 2);
                curr2 = 0; 
            }
            else{
                curr2++;
                count1 += max(0,curr1 - 2);
                curr1 = 0; 
            }
        }
        if(curr1 > 2) count1 += curr1-2;
        if(curr2 > 2) count2 += curr2-2;
        return (count1 > count2);
    }
};