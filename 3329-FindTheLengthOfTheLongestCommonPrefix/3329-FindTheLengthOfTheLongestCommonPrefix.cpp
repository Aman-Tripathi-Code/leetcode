// Last updated: 6/8/2026, 2:07:53 AM
class Solution {
public:
    struct Node {
        Node* links[10] = {nullptr};
        bool flag = false;

        bool containsKey(char ch) { return links[ch - '0'] != nullptr; }

        void put(char ch, Node* node) { links[ch - '0'] = node; }

        Node* get(char ch) { return links[ch - '0']; }

        void setEnd() { flag = true; }

        bool isEnd() { return flag; }

        ~Node() {
            for (int i = 0; i < 26; i++) {
                if (links[i] != nullptr) {
                    delete links[i];
                    links[i] = nullptr;
                }
            }
        }
    };

    class Trie{
        private:
            Node* root;
        public:
            Trie(){
                root = new Node();
            }

            ~Trie(){
                delete root;
            }

            void insert(string word){
                Node* node = root;
                for(char ch: word){
                    if(!node->containsKey(ch)){
                        node->put(ch, new Node());
                    }

                    node = node->get(ch);
                }
                node->setEnd();
            }

            int search(string word){
                Node* node = root;
                int len = word.size();
                for(int i = 0; i<len; i++){
                    if(!node->containsKey(word[i])){
                        return i;
                    }
                    node = node->get(word[i]);
                }
                return len;
            }
    };

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        Trie* trie = new Trie();
        for(int i = 0; i<m; i++){
            trie->insert(to_string(arr2[i]));
        }
        int maxi = 0;
        for(int i = 0; i<n; i++){
            string s = to_string(arr1[i]);
            int len = trie->search(s);
            maxi = max(maxi,len);
        }
        return maxi;
    }
};