class Solution {
public:
    bool check(int x) {
        vector<int> hash(10, 0);
        while(x) {
            int t = x % 10;
            if(t == 0) return false;
            hash[t]++;
            x /= 10;
        }
        for(int i = 1; i < 10; i++) {
            if(hash[i] == 0) continue;
            if(hash[i] != i) {
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        while(!check(++n));
        return n;
    }
};