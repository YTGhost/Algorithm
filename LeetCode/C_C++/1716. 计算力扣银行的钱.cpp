class Solution {
public:
    int totalMoney(int n) {
        int a = n / 7, b = n % 7;
        int a1 = (1 + 7) * 7 / 2, an = (a + (a + 6)) * 7 / 2;
        int s1 = (a1 + an) * a / 2;
        a++;
        int s2 = (a + (a + b - 1)) * b / 2;
        return s1 + s2;
    }
};