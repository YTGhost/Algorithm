class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        return (mainTank + min((mainTank - 1) / 4, additionalTank)) * 10;
    }
};

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int res = 0;
        while(mainTank >= 5) {
            int t = mainTank / 5;
            res += t * 50;
            int add = min(t, additionalTank);
            mainTank = mainTank % 5 + add;
            additionalTank -= add;
        }
        return res + mainTank * 10;
    }
};