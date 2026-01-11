// Last updated: 1/11/2026, 1:00:00 PM
class Solution {
public:
    string interpret(string command) {
        int len = command.size();
        string solution;
        for(int i = 0 ; i< len ; i++){
            if(command[i]=='"'){
                solution.push_back(command[i]);
            }
            if(command[i]=='G'){
                solution.push_back(command[i]);
            }
            if(command[i]=='('&&command[i+1]==')'){
                solution.push_back('o');
            }
            if(command[i]=='('&&command[i+1]=='a'){
                solution.push_back('a');
                solution.push_back('l');
            }
        }
        return solution;
    }
};