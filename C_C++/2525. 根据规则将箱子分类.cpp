class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool isBulky = false, isHeavy = false;
        long long volume = (long long)length * width * height;
        if((length >= 10000 || width >= 10000 || height >= 10000) || volume >= 1000000000) {
            isBulky = true;
        }
        if(mass >= 100) {
            isHeavy = true;
        }
        string res;
        if(isBulky && isHeavy) {
            res = "Both";
        } else if(!isBulky && !isHeavy) {
            res = "Neither";
        } else if(isBulky && !isHeavy) {
            res = "Bulky";
        } else if(isHeavy && !isBulky) {
            res = "Heavy";
        }
        return res;
    }
};