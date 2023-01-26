class Solution {
public:
    int countOperations(int num1, int num2) {
        int res = 0;
        while(num1 && num2) {
            res += num1 / num2;
            num1 %= num2;
            swap(num1, num2);
        }
        return res;
    }
};