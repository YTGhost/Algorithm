#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int N = 1010, M = 31 * 1440 + 10;
int cost[24];
int n;
double sum[M];

struct Record
{
    int minutes;
    string state, format_time;
    
    bool operator< (const Record& t) const {
        return minutes < t.minutes;
    }
};

map<string, vector<Record>> persons;

int main()
{
    for(int i = 0; i < 24; i++) cin >> cost[i];
    for(int i = 1; i < M; i++) sum[i] = sum[i-1] + cost[(i - 1) % 1440 / 60] / 100.0;
    cin >> n;
    char name[25], state[10], format_time[20];
    int month, day, hour, minute;
    for(int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d:%d %s", name, &month, &day, &hour, &minute, state);
        sprintf(format_time, "%02d:%02d:%02d", day, hour, minute);
        int minutes = (day - 1) * 1440 + hour * 60 + minute;
        persons[name].push_back({minutes, state, format_time});
    }
    
    for(auto person : persons) {
        auto name = person.first;
        auto records = person.second;
        sort(records.begin(), records.end());
        double total = 0;
        for(int i = 0; i < records.size() - 1; i++) {
            auto a = records[i], b = records[i + 1];
            if(a.state == "on-line" && b.state == "off-line") {
                if(!total) printf("%s %02d\n", name.c_str(), month);
                cout << a.format_time << " " << b.format_time;
                double c = sum[b.minutes] - sum[a.minutes];
                printf(" %d $%.2lf\n", b.minutes - a.minutes, c);
                total += c;
            }
        }
        if(total) printf("Total amount: $%.2lf\n", total);
    }
    return 0;
}