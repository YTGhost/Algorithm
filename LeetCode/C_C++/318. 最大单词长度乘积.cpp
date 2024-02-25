class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0, n = words.size();
        vector<int> mask(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < words[i].size(); j++) {
                mask[i] |= 1 << (words[i][j] - 'a');
            }
        }
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if((mask[i] & mask[j]) == 0) {
                    int len = words[i].size() * words[j].size();
                    res = max(res, len);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        vector<int> temp(len);
        for(int i = 0; i < len; i++) {
            string word = words[i];
            for(int j = 0; j < word.length(); j++) {
                temp[i] |= 1 << (word[j] - 'a');
            }
        }
        int res = 0;
        for(int i = 0; i < len - 1; i++) {
            for(int j = i + 1; j < len; j++) {
                if((temp[i] & temp[j]) == 0) {
                    res = max(res, int(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
};