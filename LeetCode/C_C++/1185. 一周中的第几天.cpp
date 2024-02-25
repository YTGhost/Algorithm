class Solution {
    const string weekdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
public:
    string dayOfTheWeek(int day, int month, int year) {
        tm dt = {0, 0, 0, day, month - 1, year - 1900};
        time_t t = mktime(&dt);
        return weekdays[localtime(&t)->tm_wday];
    }
};

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> ss = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        vector<int> nums = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int res = 4;
        for(int i = 1971; i < year; i++) {
            bool t = (i % 4 == 0 && i % 100 != 0) || i % 400 == 0;
            res += t ? 366 : 365;
        }
        for(int i = 1; i < month; i++) {
            res += nums[i - 1];
            if(i == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) res++;
        }
        res += day;
        return ss[res % 7];
    }
};