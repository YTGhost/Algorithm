class Solution {
public:
    string nextClosestTime(string time) {
        unordered_set<int> s;
        s.insert(time[0] - '0');
        s.insert(time[1] - '0');
        s.insert(time[3] - '0');
        s.insert(time[4] - '0');
        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3, 2));
        int t = hour * 60 + minute + 1;
        string res;
        while(1) {
            t %= 1440;
            int h = t / 60;
            int m = t % 60;
            int a1 = h / 10, a2 = h % 10, a3 = m / 10, a4 = m % 10;
            if(s.count(a1) && s.count(a2) && s.count(a3) && s.count(a4)) {
                ostringstream oss;
                oss << a1 << a2 << ":" << a3 << a4;
                res = oss.str();
                break;
            }
            t++;
        }
        return res;
    }
};