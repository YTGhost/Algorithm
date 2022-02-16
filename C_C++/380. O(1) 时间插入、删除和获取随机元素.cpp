class RandomizedSet {
public:
    unordered_map<int, int> hash;
    vector<int> list;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(hash.count(val)) return false;
        hash[val] = list.size();
        list.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!hash.count(val)) return false;
        int last = list[list.size() - 1];
        int idx = hash[val];
        list[idx] = last;
        hash[last] = idx;
        list.erase(list.end() - 1);
        hash.erase(val);
        return true;
    }
    
    int getRandom() {
        return list[rand() % list.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */