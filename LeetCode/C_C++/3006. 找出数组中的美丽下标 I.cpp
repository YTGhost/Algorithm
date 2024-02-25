class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        unordered_set<int> st;
        vector<int> m1;
        vector<int> m2;
        for(int i = 0; i <= (int)(s.size() - a.size()); i++) {
            string str = s.substr(i, a.size());
            if(str == a) {
                m1.push_back(i);
            }
        }
        for(int j = 0; j <= (int)(s.size() - b.size()); j++) {
            string str = s.substr(j, b.size());
            if(str == b) {
                m2.push_back(j);
            }
        }
        vector<int> res;
        int i = 0, j = 0;
        while(i < m1.size() && j < m2.size()) {
            if(abs(m1[i] - m2[j]) <= k) {
                res.push_back(m1[i]);
                i++;
            } else if(m1[i] < m2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};