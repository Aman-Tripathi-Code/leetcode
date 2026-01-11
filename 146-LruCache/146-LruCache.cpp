// Last updated: 1/11/2026, 1:02:48 PM
class LRUCache {
public:
    //this is the structure for doubly-linked list;
    class node{
        public:
        int key;
        int value;
        node* prev;
        node* next;
        node(int _key, int _value){
            key = _key;
            value = _value;
        }
    } ;
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap = 0;
    unordered_map<int,node*> mp;
    
    //intialize the cap and doubly linked list constructor
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node* newNode){
        node* temp = head->next; 
        newNode->prev = head;
        newNode->next = temp;
        head->next = newNode;
        temp->prev = newNode;
    }
    void deleteNode(node* delNode){
        node* delPrev = delNode->prev;
        node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            //that is the key is already in map
            node* resNode = mp[key];
            int resVal = resNode->value;
            //now we will delete that node from LL and map and reinsert after the head
            deleteNode(resNode);
            mp.erase(key);
            addNode(resNode);
            mp[key] = head->next;
            return resVal;
        }
        //if the key doesn't exist in the map
        return -1;
    }
    
    void put(int key, int value) {
        //if the key is already present in the map
        if(mp.find(key) != mp.end()){
            node* existingNode = mp[key];
            //delete the node from the LL and map
            deleteNode(existingNode);
            mp.erase(key);
        }
        //if the map if full
        if(mp.size()==cap){
            node* LRU = tail->prev;
            //delete the LRU
            deleteNode(LRU);
            mp.erase(LRU->key);
        }
        //add a node just after the node and in the map
        addNode(new node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */