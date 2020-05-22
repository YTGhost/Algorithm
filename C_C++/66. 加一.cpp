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