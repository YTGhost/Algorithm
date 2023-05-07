class Solution {
public:
    int countTime(string time) {
        int res = 1;
        if(time[0] == '?' && time[1] == '?') {
            res *= 24;
        } else if(time[0] == '?') {
            res *= time[1] < '4' ? 3 : 2;
        } else if(time[1] == '?') {
            res *= time[0] < '2' ? 10 : 4;
        }
        if(time[3] == '?' && time[4] == '?') {
            res *= 60;
        } else if(time[3] == '?') {
            res *= time[4] >= '0' ? 6 : 7;
        } else if(time[4] == '?') {
            res *= 10;
        }
        return res;
    }
};