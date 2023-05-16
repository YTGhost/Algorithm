class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> st(s.begin(), s.end());
        for(int i = 25; i >= 0; i--) {
            if(st.count('a' + i) && st.count('A' + i)) {
                return string(1, 'A' + i);
            }
        }
        return "";
    }
};