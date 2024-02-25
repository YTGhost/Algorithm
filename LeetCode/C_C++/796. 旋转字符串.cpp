class Solution {
public:
    bool rotateString(string s, string goal) {
        string str = s + s;
        return s.length() == goal.length() && str.find(goal) != -1;
    }
};