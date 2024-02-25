// 2021/03/29 每日一题
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int i = 32;
        while(i--)
        {
            res <<= 1;
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int i = 32;
        while(i--)
        {
            res <<= 1;
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};