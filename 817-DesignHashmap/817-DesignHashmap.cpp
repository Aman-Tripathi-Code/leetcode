// Last updated: 1/11/2026, 1:01:06 PM
class MyHashMap {
public:
    int hs[1000001];
    MyHashMap() {
        memset(hs,-1,sizeof(hs));
    }
    
    void put(int key, int value) {
        hs[key] = value;
    }
    
    int get(int key) {
        return hs[key];
    }
    
    void remove(int key) {
        hs[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */