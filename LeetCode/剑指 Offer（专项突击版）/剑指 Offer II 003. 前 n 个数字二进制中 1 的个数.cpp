// dp O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for(int i = 1; i <= n; i++) {
            res[i] = res[i & (i - 1)] + 1;
        }
        return res;
    }
};

// Brian Kernighan algorithm O(nlogn)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for(int i = 0; i <= n; i++) {
            res[i] = toCount(i);
        }
        return res;
    }
    int toCount(int x) {
        int cnt = 0;
        while(x) {
            x &= x - 1;
            cnt++;
        }
        return cnt;
    }
};