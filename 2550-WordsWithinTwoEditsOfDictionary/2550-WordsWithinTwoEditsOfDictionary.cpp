// Last updated: 6/8/2026, 2:08:13 AM
class Solution {
public:
    // O(n)
    bool withinTwoEdits(const string& query, const string& dict) {
        int n = query.size(), numOfEdits = 0;
        for (int i = 0; i < n; i++) {
            if (query[i] != dict[i]) {
                numOfEdits++;
                if (numOfEdits > 2) {
                    return false;
                }
            }
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> result;
        for(string query : queries){
            for(string word : dictionary) {
                if (withinTwoEdits(query, word)) {
                    result.push_back(query);
                    break;
                }
            }
        }
        return result;
    }
};