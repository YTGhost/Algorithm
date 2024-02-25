// 每日一题打卡
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size()-1;
        while(l < r)
            swap(s[l++], s[r--]);
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while(l < r) swap(s[l++], s[r--]);
    }
};