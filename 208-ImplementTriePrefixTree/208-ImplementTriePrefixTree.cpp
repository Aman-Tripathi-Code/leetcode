// Last updated: 1/11/2026, 1:02:29 PM
//1.Make a struct node with two member 
//i) An array of node with 26 different node addresses
//ii) A boolean flag 
//2.In trie class make a node root and in the constructor of  trie assign root as new node
//3.In insert function make a node pointing to root
//4.Run a loop for the length of the word and for every character check whether it already exist 
//4.1 Make a function containsKey in struct which will check whether the link array has null or not
//      for the given character
//4.2 if the element do not exist we will make a function put in struct with parameter as char and new 
//      node and in struct this function will assign then link array a new node
//4.3 now we will join this node with our previous node and make a function get to which will 
// return the address of the new node 
//4.4 now as the traversal end for the word we will left with last reference node and we will set its flag as true by creating a new function setEnd 

// when searching we start with root node and traverse for the word length and if the searchkey function
// return false we will return false
//else we will assign node with node address of that key with the help of get function
//make a function isEnd to check whether the flag value is true or not when the traversal ends

//in start with function every thing is same as search function only if the function do not return false
// we will return true;
struct Node{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node *get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i = 0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            //move to reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i<prefix.size(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */