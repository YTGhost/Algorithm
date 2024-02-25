class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 60; j++) {
                if(__builtin_popcount(i) + __builtin_popcount(j) == turnedOn) {
                    string t = "";
                    t += to_string(i);
                    t += ':';
                    t += j < 10 ? "0" + to_string(j) : to_string(j);
                    res.push_back(t);
                }
            }
        }
        return res;
    }
};