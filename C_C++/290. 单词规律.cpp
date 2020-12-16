class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> c2str;
        unordered_map<string, char> str2c;
        vector<string> v;
        for(int i = 0; i < s.length();)
        {
            int start = i;
            int num = 0;
            while(i < s.length() && s[i++] != ' ') num++;
            v.emplace_back(s.substr(start, num));
        }
        if(pattern.length() != v.size()) return false;
        for(int i = 0; i < pattern.length(); i++)
        {
            string word = v[i];
            auto search = c2str.find(pattern[i]);
            auto search1 = str2c.find(word);
            if(search1 != str2c.end() && search1->second != pattern[i]) {
                return false;
            }
            if(search != c2str.end()) {
                if(search->second != word) {
                    return false;
                }
            } else {
                c2str[pattern[i]] = word;
                str2c[word] = pattern[i]; 
            }
        }
        return true;
    }
};