class MapSum {
public:
    /** Initialize your data structure here. */
    struct Trie {
        vector<Trie*> children;
        bool isEnd;
        string key;
        Trie() : children(26), isEnd(false) {}
    };
    unordered_map<string, int> hash;
    Trie* root;
    MapSum() {
        root = new Trie();
    }

    void toInsert(string key) {
        auto p = root;
        for(auto c : key) {
            int t = c - 'a';
            if(!p->children[t]) {
                p->children[t] = new Trie();
            }
            p = p->children[t];
        }
        p->isEnd = true;
        p->key = key;
    }
    
    void insert(string key, int val) {
        if(!hash.count(key)) {
            toInsert(key);
        }
        hash[key] = val;
    }
    
    int sum(string prefix) {
        int sum = 0;
        auto p = root;
        for(auto c : prefix) {
            int t = c - 'a';
            if(!p->children[t]) {
                return 0;
            }
            p = p->children[t];
        }
        queue<Trie*> q;
        q.push(p);
        while(!q.empty()) {
            auto item = q.front();
            q.pop();
            if(item->isEnd) {
                sum += hash[item->key];
            }
            for(int i = 0; i < 26; i++) {
                if(item->children[i]) {
                    q.push(item->children[i]);
                }
            }
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */