class Trie {
public:
    /** Initialize your data structure here. */
    Trie* children[26];

    Trie() {
        for(int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
    
    int insert(string word) {
        Trie* root = this;
        bool isNew = false;
        for(int i = word.length()-1; i >= 0; i--)
        {
            char c = word[i];
            if(!root->children[c-'a']){
                root->children[c-'a'] = new Trie();
                isNew = true;
            }
            root = root->children[c-'a'];
        }
        return isNew ? word.length() + 1 : 0;
    }
};

class Solution {
public:
    static bool less(const string& str1, const string& str2){
        return str1.length() > str2.length();
    }
    int minimumLengthEncoding(vector<string>& words) {
        int count = 0;
        sort(words.begin(), words.end(), less);
        Trie* root = new Trie();
        for(string word : words)
        {
            count += root->insert(word);
        }
        return count;
    }
};