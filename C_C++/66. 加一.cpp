class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1; i >= 0; i--)
        {
            if(++digits[i] == 10){
                digits[i] = 0;
                if(i == 0) digits.insert(digits.begin(), 1);
            }
            else break;
        }
        return digits;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(carry == 1) {
                if(digits[i] == 9) digits[i] = 0;
                else digits[i]++, carry = 0;
            }
        }
        if(carry == 1) {
            vector<int> t(digits.size() + 1);
            t[0] = 1;
            for(int i = 0; i < digits.size(); i++) {
                t[i + 1] = digits[i];
            }
            return t;
        }
        return digits;
    }
};