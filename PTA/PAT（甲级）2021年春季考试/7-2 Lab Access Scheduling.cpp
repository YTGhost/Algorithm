#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Range {
    string start, end;
    
    bool operator< (const Range& t) const {
        return end < t.end;
    }
};

int n;

int main()
{
    cin >> n;
    vector<Range> ranges;
    for(int i = 0; i < n; i++) {
        string start, end;
        cin >> start >> end;
        ranges.push_back({start, end});
    }
    sort(ranges.begin(), ranges.end());
    int res = 1, last = 0;
    for(int i = 1; i < n; i++) {
        if(ranges[i].start >= ranges[last].end) {
            res++;
            last = i;
        }
    }
    cout << res;
    return 0;
}