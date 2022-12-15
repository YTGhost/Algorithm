class Solution {
public:
    int getLucky(string s, int k) {
        string str;
        for(auto c : s) {
            str += to_string(c - 'a' + 1);
        }
        string res = str;
        while(k--) {
            int temp = 0;
            for(auto c : res) {
                temp += c - '0';
            }
            res = to_string(temp);
        }
        return stoi(res);
    }
};