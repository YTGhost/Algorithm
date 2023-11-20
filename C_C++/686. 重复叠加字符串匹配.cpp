class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int res = -1;
        for(int i = 0; i < a.size(); i++) {
            int l = i, r = 0;
            int cnt = 1;
            while(r < b.size() && a[l % a.size()] == b[r]) {
                l++;
                r++;
                if(l == a.size() && r != b.size()) {
                    cnt++;
                    l %= a.size();
                }
            }
            if(r >= b.size()) {
                res = max(res, cnt);
                break;
            }
        }
        return res;
    }
};

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.length(), m = b.length();
        int res = 0;
        string temp = "";
        while(temp.length() < m) {
            temp += a;
            res++;
        }
        temp += a;
        int idx = temp.find(b);
        if(idx == -1) return -1;
        else if(idx + b.length() > res * n) return res + 1;
        else return res;
    }
};