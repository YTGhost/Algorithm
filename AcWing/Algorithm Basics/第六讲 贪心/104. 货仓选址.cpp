#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int res = 0, idx = n / 2;
    for(int i = 0; i < n; i++) {
        res += abs(a[idx] - a[i]);
    }
    cout << res << endl;
    return 0;
}