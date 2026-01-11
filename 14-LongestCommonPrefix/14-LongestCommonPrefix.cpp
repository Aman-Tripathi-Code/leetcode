// Last updated: 1/11/2026, 1:04:12 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        int len = strs.size();
        if(strs.size()==1){
            s = strs[0];
        }
        else{
            int index =0, mini = strs[0].size();
            for(int i =1; i<len; i++){
                int length = strs[i].size();
                if(length<mini){
                    mini = min(mini,length);
                    index = i;
                }
            }
            for(int i =0; i<mini; i++){
                int cnt =0;
                for(int j =0; j<len; j++){
                    if(strs[index][i]==strs[j][i]){
                        cnt++;
                    }
                }
                if(cnt==len){
                        s.push_back(strs[index][i]);
                    }
                else break;
            }
           
        }
        return s;
    }
};