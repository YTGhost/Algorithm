class Solution {
public:
    bool check(int x) {
        int num = x;
        while(x) {
            int t = x % 10;
            if(t == 0 || num % t != 0) return false;
            x /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right; i++) {
            if(check(i)) res.push_back(i);
        }
        return res;
    }
};