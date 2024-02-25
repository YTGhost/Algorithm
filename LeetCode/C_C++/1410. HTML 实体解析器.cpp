class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, string> s = {
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"}
        };
        int n = text.size();
        string res;
        for(int i = 0; i < n;) {
            auto c = text[i];
            if(c == '&') {
                int j = i;
                while(j < n && text[j] != ';') {
                    j++;
                }
                string str = text.substr(i, j - i + 1);
                if(s.find(str) != s.end()) {
                    res += s[str];
                    i = j + 1;
                    continue;
                }
            }
            res += text[i++];
        }
        return res;
    }
};