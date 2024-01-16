class Solution {
public:
    vector<int> computeLPSArray(const string& pattern) {
        vector<int> lps(pattern.size(), 0);
        int len = 0;
        int i = 1;

        while (i < pattern.size()) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    vector<int> KMPsearch(const string& text, const string& pattern) {
        vector<int> matches;
        vector<int> lps = computeLPSArray(pattern);
        int i = 0; // Index for text
        int j = 0; // Index for pattern

        while (i < text.size()) {
            if (pattern[j] == text[i]) {
                j++;
                i++;
            }

            if (j == pattern.size()) {
                matches.push_back(i - j);
                j = lps[j - 1];
            } else if (i < text.size() && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i = i + 1;
                }
            }
        }

        return matches;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> m1 = KMPsearch(s, a);
        vector<int> m2 = KMPsearch(s, b);
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