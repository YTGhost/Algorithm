class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(password.length() < 8) return false;
        bool hasUpper = false, hasLower = false, hasNumber = false, hasSpecial = false;
        unordered_set<char> specials = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
        for(int i = 0; i < password.length(); i++) {
            if(i > 0 && password[i] == password[i - 1]) return false;
            char c = password[i];
            if(islower(c)) hasLower = true;
            else if(isupper(c)) hasUpper = true;
            else if(isdigit(c)) hasNumber = true;
            else if(specials.count(c)) hasSpecial = true;
        }
        return hasUpper && hasLower && hasNumber && hasSpecial;
    }
};