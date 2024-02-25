#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100010;
int n;

struct Range{
    int l, r;
    
    bool operator< (const Range& t) const {
        return l < t.l;
    }
}ranges[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ranges[i].l = l, ranges[i].r = r;
    }
    sort(ranges, ranges + n);
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; i++) {
        if(q.empty() || q.top() >= ranges[i].l) q.push(ranges[i].r);
        else {
            q.pop();
            q.push({ranges[i].r});
        }
    }
    cout << q.size() << endl;
    return 0;
}