class MyCalendar {
public:
    map<int, int> hash;
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        auto item = hash.lower_bound(start);
        if(item != hash.end() && item->first < end) return false;
        if(item != hash.begin() && (--item)->second > start) return false;
        hash[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */