struct DLinkedNode {
    int key, val;
    DLinkedNode* pre;
    DLinkedNode* next;
    DLinkedNode(): key(0), val(0), pre(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _val): key(_key), val(_val), pre(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode *head, *tail;
    int n, cap;
    LRUCache(int capacity) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->pre = head;
        cap = capacity;
        n = 0;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)) {
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            n++;
            if(n > cap) {
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                n--;
            }
        } else {
            DLinkedNode* node = cache[key];
            node->val = value;
            moveToHead(node);
        }
    }
    void addToHead(DLinkedNode* node) {
        node->pre = head;
        node->next = head->next;
        head->next = node;
        node->next->pre = node;
    }
    void removeNode(DLinkedNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }
    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->pre;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */