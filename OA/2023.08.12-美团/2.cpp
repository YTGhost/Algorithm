#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> s(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) {
        s[i] += a[i - 1] + s[i - 1];
    }
    int x, y;
    cin >> x >> y;
    if(x == y) {
        cout << 0 << endl;
        return 0;
    } else if(x > y) {
        swap(x, y);
    }
    x--, y--;
    cout << min(s[y] - s[x], s[x] + a[n - 1] + s[n - 1] - s[y]) << endl;
    return 0;
}