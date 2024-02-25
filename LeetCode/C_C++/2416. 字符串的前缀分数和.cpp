class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        struct Node {
            Node *son[26]{};
            int score = 0;
        };
        Node *root = new Node();
        for(auto &word : words) {
            auto cur = root;
            for(auto c : word) {
                c -= 'a';
                if(cur->son[c] == NULL) {
                    cur->son[c] = new Node();
                }
                cur = cur->son[c];
                cur->score += 1;
            }
        }
        int n = words.size();
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            auto cur = root;
            for(auto c : words[i]) {
                cur = cur->son[c - 'a'];
                res[i] += cur->score;
            }
        }
        return res;
    }
};