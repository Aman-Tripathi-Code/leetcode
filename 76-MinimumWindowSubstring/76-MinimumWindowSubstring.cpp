// Last updated: 1/11/2026, 1:03:31 PM
class Solution {
public:
    string minWindow(string s, string t) {
        // map to store the element of t string with their respective frequency
        unordered_map<char,int> mp;
        for(int i = 0; i<t.size(); i++){
            mp[t[i]]++;
        }
        
        //we will intialize the variable for sliding window
        //we will also intialize two variable start and end which will mark the start and end
        //of the substring window
        int  i = 0, j = 0, start = 0,end = INT_MAX;
        int count = mp.size();
        //start of the variable sliding window
        while(j<s.size()){
            //if the element is present in map 
            //we will decrease its freq
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;//if the freq of that element is zero we will decrease the count 
                    //i.e. we have all the count of that element in that window
                }
            }
            // we will have all the elements of substring in our window the count will reach 0
            if(count==0){
                while(count==0){
                    if(end>j-i+1){//if the end of substring if greater than the window size
                        end = min(end,j-i+1);// we will resize the end to a smaller number
                        start = i; // and start to the starting of the window 
                    }
                    //as we have find the ans for that window we increase the count by checking
                    //the element from start and change the window
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                            if(mp[s[i]]>0){
                                count++;
                            }
                    }
                    i++;
                }
            }
            j++;
        }
        if(end == INT_MAX) return "";
        return s.substr(start,end);
    }
};