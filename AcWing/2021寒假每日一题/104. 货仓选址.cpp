#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int a[N];

// 贪心，取中位数
int main()
{
    int n;
    int res = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int mid = a[n >> 1];
    for(int i = 0; i < n; i++) res += abs(mid - a[i]);
    cout << res << endl;
    return 0;
}