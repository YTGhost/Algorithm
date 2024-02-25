class Solution {
public:
    int dayOfYear(string date) {
        tm dt;
        istringstream(date) >> get_time(&dt, "%Y-%m-%d");
        return dt.tm_yday + 1;
    }
};