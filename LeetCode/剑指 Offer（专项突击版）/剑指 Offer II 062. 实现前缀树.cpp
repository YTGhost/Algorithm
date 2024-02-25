class Trie {
public:
    vector<Trie*> children;
    bool isEnd;
    /** Initialize your data structure here. */
    Trie() {
        children = vector<Trie*>(26);
        isEnd = false;
    }

    Trie* searchPrefix(string word) {
        auto node = this;
        for(auto c : word) {
            int t = c - 'a';
            if(!node->children[t]) {
                return NULL;
            }
            node = node->children[t];
        }
        return node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto node = this;
        for(auto c : word) {
            int t = c - 'a';
            if(!node->children[t]) {
                node->children[t] = new Trie();
            }
            node = node->children[t];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto node = searchPrefix(word);
        return node && node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto node = searchPrefix(prefix);
        return node ? true : false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */