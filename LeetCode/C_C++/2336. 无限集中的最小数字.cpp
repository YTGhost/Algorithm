class SmallestInfiniteSet {
public:
    set<int> s;
    int cnt = 1;
    SmallestInfiniteSet() {

    }
    
    int popSmallest() {
        int res;
        if(s.empty()) {
            res = cnt++;
            return res;
        }
        res = *s.begin();
        s.erase(s.begin());
        return res;
    }
    
    void addBack(int num) {
        if(num < cnt) {
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */