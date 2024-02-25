class Solution {
public:
    bool isValid(string s) {
        string str;
        for(auto c : s) {
            str.push_back(c);
            if(str.size() >= 3 && str.substr(str.size() - 3, 3) == "abc") {
                str.erase(str.size() - 3, 3);
            }
        }
        return str.size() == 0;
    }
};