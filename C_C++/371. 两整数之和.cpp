class Solution {
public:
    int getSum(int a, int b) {
        int sum, carry;
        sum = a ^ b;
        carry = ((unsigned int)a & b) << 1;
        if(carry != 0) return getSum(sum, carry);
        return sum;
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a^b, ((unsigned int)a&b) << 1);
    }
};