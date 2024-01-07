class Trie {
public:
    struct Node {
        Node *son[26]{};
        bool isEnd;
    };
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        auto cur = root;
        for(auto c : word) {
            if(cur->son[c - 'a'] == NULL) {
                cur->son[c - 'a'] = new Node();
            }
            cur = cur->son[c - 'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        auto cur = root;
        for(auto c : word) {
            if(cur->son[c - 'a'] == NULL) {
                return false;
            }
            cur = cur->son[c - 'a'];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        auto cur = root;
        for(auto c : prefix) {
            if(cur->son[c - 'a'] == NULL) {
                return false;
            }
            cur = cur->son[c - 'a'];
        }
        return true;
    }
};

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    bool isWord;
    Trie* children[26];

    Trie() {
        isWord = false;
        for(int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for(char c : word)
        {
            if(!root->children[c-'a'])   root->children[c-'a'] = new Trie();
            root = root->children[c-'a'];
        }
        root->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for(char c : word)
        {
            if(!root->children[c-'a']) return false;
            root = root->children[c-'a'];
        }
        return root->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for(char c : prefix)
        {
            if(!root->children[c-'a']) return false;
            root = root->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */