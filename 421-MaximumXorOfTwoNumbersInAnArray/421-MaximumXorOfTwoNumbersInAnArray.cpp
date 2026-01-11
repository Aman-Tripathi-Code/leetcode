// Last updated: 1/11/2026, 1:01:51 PM
class Solution {
struct Node{
    Node* links[2];

    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }

    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(int num){
            Node *node = root;
            for(int i = 31; i>=0; i--){
                int bit = (num>>i)&1;
                if(!node->containsKey(bit)){
                    node->put(bit,new Node());
                }
                node = node->get(bit);
            }
        }

        int maxXor(int num){
            Node * node = root;
            int maxi = 0;
            for(int i = 31; i>=0; i--){
                int bit = (num>>i)&1;
                if(!node->containsKey(1-bit)){
                    node = node->get(bit);
                }
                else{
                    maxi = maxi|(1<<i);
                    node = node->get(1-bit);
                }
            }
            return maxi;
        }

};
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *trie = new Trie();
        for(auto &it:nums){
            trie->insert(it);
        }
        int maxi = 0;
        for(auto &it:nums){
            int curr = trie->maxXor(it);
            maxi = max(maxi,curr);
        }
        return maxi;
    }
};