class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(auto money : bills) {
            if(money == 5) {
                five++;
            } else if(money == 10) {
                if(five == 0) return false;
                ten++;
                five--;
            } else {
                if(five > 0 && ten > 0) {
                    five--;
                    ten--;
                } else if(five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};