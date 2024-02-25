class MagicDictionary {
public:
    unordered_map<int, vector<string>> hash;
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        for(auto word : dictionary) {
            hash[word.length()].push_back(word);
        }
    }
    
    bool search(string searchWord) {
        int n = searchWord.length();
        vector<string> targets = hash[n];
        for(auto target : targets) {
            bool isValid = true;
            bool flag = false;
            for(int i = 0; i < n; i++) {
                if(searchWord[i] != target[i]) {
                    if(!flag) flag = true;
                    else {
                        isValid = false;
                        break;
                    }
                }
            }
            if(flag &&isValid) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */