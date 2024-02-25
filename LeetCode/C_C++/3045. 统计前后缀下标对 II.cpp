class Solution {
public:
    struct Node {
        Node *son[26]{};
        int cnt = 0;
    };
    vector<int> z_function(string s) {
        int n = s.length();
        vector<int> z(n);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(z[i - l], r - i + 1);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                l = i;
                r = i + z[i];
                z[i]++;
            }
        }
        z[0] = n; // 该题也需要囊括自身
        return z;
    }
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long res = 0;
        Node *root = new Node();
        for(string& word : words) {
            int n = word.length();
            vector<int> z = z_function(word);
            auto cur = root;
            for(int i = 0; i < n; i++) {
                int c = word[i] - 'a';
                if(!cur->son[c]) {
                    cur->son[c] = new Node();
                }
                cur = cur->son[c];
                if(z[n - i - 1] == i + 1) {
                    res += cur->cnt;
                }
            }
            cur->cnt++;
        }
        return res;
    }
};