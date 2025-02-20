class Solution {
    public:
        vector<int> evenOddBit(int n) {
            int idx = 0, even = 0, odd = 0;
            while (n) {
                if (n & 1) {
                    even += idx % 2 == 0;
                    odd += idx % 2 == 1;
                }
                n >>= 1;
                idx++;
            }
            return {even, odd};
        }
    };