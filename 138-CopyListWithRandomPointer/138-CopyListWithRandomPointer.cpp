// Last updated: 1/11/2026, 1:02:53 PM
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ptr = head;
        unordered_map<Node*,Node*> mp;
        while(ptr){
            Node* temp = new Node(ptr->val);
            mp[ptr] = temp;
            ptr = ptr->next;
        }
        ptr = head;
        while(ptr){
            Node *next = ptr->next;
            Node *random = ptr->random;
            mp[ptr]->next = mp[next];
            mp[ptr]->random = mp[random];
            ptr = ptr->next;
        }
        return mp[head];
    }
};