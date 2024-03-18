class Node {
public:
    int key, value;
    Node *prev, *next;

    Node(int k = 0, int v = 0) : key(k), value(v) {}
};

class LRUCache {
private:
    int capacity;
    Node *dummy;
    unordered_map<int, Node*> key2node;

    void remove(Node *x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    void push_front(Node *x) {
        x->next = dummy->next;
        dummy->next->prev = x;
        dummy->next = x;
        x->prev = dummy;
    }

    Node* get_node(int key) {
        auto it = key2node.find(key);
        if(it == key2node.end()) {
            return NULL;
        }
        auto node = it->second;
        remove(node);
        push_front(node);
        return node;
    }
public:
    LRUCache(int capacity) : capacity(capacity), dummy(new Node()) {
        dummy->next = dummy;
        dummy->prev = dummy;
    }
    
    int get(int key) {
        auto node = get_node(key);
        return node ? node->value : -1;
    }
    
    void put(int key, int value) {
        auto node = get_node(key);
        if(node) {
            node->value = value;
            return;
        }
        node = new Node(key, value);
        key2node[key] = node;
        push_front(node);
        if(key2node.size() > capacity) {
            auto last_node = dummy->prev;
            key2node.erase(last_node->key);
            remove(last_node);
            delete last_node;
        }
    }
};

struct DLinkedNode {
        int key, value;
        DLinkedNode* prev;
        DLinkedNode* next;
        DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
        DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
    };

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        // 使用伪头部和伪尾部结点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        // 如果key存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            // 如果key不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            size++;
            if(size > capacity){
                // 如果超出容量，删除双向链表的尾部结点
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                size--;
            }
        }else{
            // 如果key存在，就通过哈希表定位，再修改value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail(){
        DLinkedNode* node = tail->prev;
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