// Last updated: 1/11/2026, 1:00:59 PM
class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>> st;
    int next(int price) {
        int span = 1;
        while(!st.empty() && price >= st.top().first){
            span += st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */