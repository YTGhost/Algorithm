class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.length();
        unordered_set<string> st;
        for(int i = 0; i < n - 1; i++) {
            st.insert(s.substr(i, 2));
        }
        reverse(s.begin(), s.end());
        for(int i = 0; i < n - 1; i++) {
            string str = s.substr(i, 2);
            if(st.contains(str)) {
                return true;
            }
        }
        return false;
    }
};