class Solution {
public:
    int secondHighest(string s) {
        set<int> S;
        for(auto c : s)
            if(isdigit(c)) S.insert(c - '0');
        if(S.size() <= 1) return -1;
        auto it = S.rbegin();
        it++;
        return *it;
    }
};

class Solution {
public:
    int secondHighest(string s) {
        vector<int> a;
        for(int i = 0; i < s.length(); i++)
            if(isdigit(s[i])) a.push_back(s[i] - '0');
        if(a.empty() || a.size() == 1) return -1;
        sort(a.begin(), a.end(), [](int c, int d) {
            return c > d;
        });
        int t = a[0], res = -1;
        for(int i = 1; i < a.size(); i++)
            if(a[i] < t) {
                res = a[i];
                break;
            }
        return res;
    }
};