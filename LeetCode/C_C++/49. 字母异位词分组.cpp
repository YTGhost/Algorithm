class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;
        for(auto str : strs) {
            vector<int> hash(26);
            for(auto c : str) {
                hash[c - 'a']++;
            }
            string key = "";
            for(int i = 0; i < 26; i++) {
                if(hash[i]) {
                    key += 'a' + i;
                    key += to_string(hash[i]);
                }
            }
            m[key].push_back(str);
        }
        for(auto &[_, v] : m) {
            res.push_back(v);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            m[key].emplace_back(str);
        }
        vector<vector<string>> res;
        for(auto item : m) {
            res.emplace_back(item.second);
        }
        return res;
    }
};