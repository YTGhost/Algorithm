class Solution {
public:
    struct Trie {
        vector<Trie*> children;
        bool isEnd;
        Trie() : children(26), isEnd(false) {}
    };
    Trie* root;
    void insert(string word) {
        auto node = root;
        for(auto c : word) {
            int t = c - 'a';
            if(!node->children[t]) {
                node->children[t] = new Trie();
            }
            node = node->children[t];
        }
        node->isEnd = true;
    }
    string search(string word) {
        auto node = root;
        string str = "";
        for(auto c : word) {
            int t = c - 'a';
            if(!node->children[t]) {
                return word;
            } else {
                str += c;
            }
            node = node->children[t];
            if(node->isEnd) break;
        }
        return str;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> res;
        root = new Trie();
        for(auto root : dictionary) {
            insert(root);
        }
        for(int i = 0; i < sentence.length(); i++) {
            int j = i;
            while(j < sentence.length() && sentence[j] != ' ') {
                j++;
            }
            string word = sentence.substr(i, j - i);
            string newWord = search(word);
            res.push_back(newWord);
            i = j;
        }
        string str = "";
        for(int i = 0; i < res.size(); i++) {
            if(i) str += " " + res[i];
            else str += res[i];
        }
        return str;
    }
};