// Last updated: 1/11/2026, 1:02:17 PM
class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> q1,q2;
    void push(int x) {
        while(!q1.empty()){
            q2.push(q1.top());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.top());
            q2.pop();
        }
    }
    
    int pop() {
        if(q1.empty()) return -1;
        int temp = q1.top();
        q1.pop();
        return temp;
    }
    
    int peek() {
        return q1.top();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */