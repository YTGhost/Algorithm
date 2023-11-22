class Solution {
public:
    static const int N = 20010;
    int tr[N];
    int n;
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int c) {
        for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }
    int sum(int x) {
        int res = 0;
        for(int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }
    int kEmptySlots(vector<int>& bulbs, int k) {
        n = bulbs.size();
        int res = -1;
        vector<bool> hash(n + 1);
        for(int i = 0; i < n; i++) {
            int y = bulbs[i];
            add(y, 1);
            hash[y] = true;
            if(y - k - 1 >= 1 && hash[y - k - 1] && sum(y - 1) - sum(y - k - 1) == 0) {
                return i + 1;
            }
            if(y + k + 1 <= n && hash[y + k + 1] && sum(y + k) - sum(y) == 0) {
                return i + 1;
            }
        }
        return -1;
    }
};