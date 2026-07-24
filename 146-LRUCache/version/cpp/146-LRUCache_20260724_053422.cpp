// Last updated: 7/24/2026, 5:34:22 AM
1class Node {
2public:
3    int key;
4    int val;
5    Node* prev;
6    Node* next;
7
8    Node(int key, int val) {
9        prev = nullptr;
10        next = nullptr;
11        this->key = key;
12        this->val = val;
13    }
14};
15
16class LRUCache {
17
18public:
19    int capacity;
20    unordered_map<int, Node*> mp;
21    Node* head = new Node(-1, -1);
22    Node* tail = new Node(-1, -1);
23
24    LRUCache(int capacity) {
25        this->capacity = capacity;
26        head->next = tail;
27        tail->prev = head;
28    }
29
30    int get(int key) {
31        if (mp.find(key) != mp.end()) {
32            Node* node = mp[key];
33            removeNode(node);
34            addAtFront(node);
35            return node->val;
36        } else {
37            return -1;
38        }
39    }
40
41    void put(int key, int value) {
42        if (mp.find(key) != mp.end()) {
43            Node* node = mp[key];
44            node->val = value;
45            removeNode(node);
46            addAtFront(node);
47        } else {
48            if (mp.size() == capacity) {
49                mp.erase(tail->prev->key);
50                removeNode(tail->prev);
51            }
52
53            Node* newNode = new Node(key, value);
54            mp[key] = newNode;
55            addAtFront(newNode);
56        }
57    }
58
59    void removeNode(Node* node) {
60        node->prev->next = node->next;
61        node->next->prev = node->prev;
62    }
63
64    void addAtFront(Node* node) {
65        node->prev = head;
66        node->next = head->next;
67        head->next->prev = node;
68        head->next = node;
69    }
70};
71
72/**
73 * Your LRUCache object will be instantiated and called as such:
74 * LRUCache* obj = new LRUCache(capacity);
75 * int param_1 = obj->get(key);
76 * obj->put(key,value);
77 */