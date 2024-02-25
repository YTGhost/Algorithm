class StockSpanner {
public:
    stack<pair<int, int>> stk;
    int day = -1;
    StockSpanner() {
        stk.push({-1, INT_MAX});
    }
    
    int next(int price) {
        day++;
        while(price >= stk.top().second) {
            stk.pop();
        }
        int res = day - stk.top().first;
        stk.push({day, price});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */