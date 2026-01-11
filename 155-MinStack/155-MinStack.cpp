// Last updated: 1/11/2026, 1:02:44 PM
class MinStack {
public:
    MinStack() {
        
    }
    stack<long long> st;
    long long mini = INT_MAX;
    void push(int value) {
        long long val = value;
        if(st.empty()){
            mini = val; 
            st.push(val);
        }
        else{
            if(val < mini){
                st.push(2*val*1LL - mini);
                mini = val;
            }
            else st.push(val);
        }   
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top() < mini){
            mini = 2*mini - st.top();
            cout << st.top() << ' ' << mini << endl;
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        if(st.top() < mini){
            return mini;
        }
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */