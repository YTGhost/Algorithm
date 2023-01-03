class Solution {
public:
    bool areNumbersAscending(string s) {
        int last = -1;
        for(int i = 0; i < s.length(); i++) {
            string temp = "";
            while(isdigit(s[i])) {
                temp += s[i];
                i++;
            }
            if(temp == "") continue;
            int num = stoi(temp);
            if(num > last) last = num;
            else return false;
        }
        return true;
    }
};