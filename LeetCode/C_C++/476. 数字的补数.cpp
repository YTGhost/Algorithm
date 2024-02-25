class Solution {
public:
    int findComplement(int num) {
        int t = num, c = 0;
        while(t) {
            t >>= 1;
            c = (c << 1) + 1;
        }
        return num ^ c;
    }
};