class StockPrice {
public:
    map<int, int> hm;
    map<int, int> m;
    int curTimestamp = 0;
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        curTimestamp = max(curTimestamp, timestamp);
        if(hm.count(timestamp)) {
            int old = hm[timestamp];
            int cnt = m[old];
            if(cnt == 1) {
                m.erase(old);
            } else {
                m[old] = cnt - 1;
            }   
        }
        hm[timestamp] = price;
        m[price]++;
    }
    
    int current() {
        return hm[curTimestamp];
    }
    
    int maximum() {
        return m.rbegin()->first;
    }
    
    int minimum() {
        return m.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */