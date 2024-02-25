#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

struct Range{
    int a, b;
    
    bool operator< (const Range& t) const {
        return b < t.b;
    }
}ranges[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ranges[i] = {a, b};
    }
    sort(ranges, ranges + n);
    int res = 1, last = 0;
    for(int i = 1; i < n; i++) {
        if(ranges[i].a > ranges[last].b) {
            res++;
            last = i;
        }
    }
    cout << res << endl;
    return 0;
}