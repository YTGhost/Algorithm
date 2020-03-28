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