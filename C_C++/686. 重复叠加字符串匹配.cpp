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