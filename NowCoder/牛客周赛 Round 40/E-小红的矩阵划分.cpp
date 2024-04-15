#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, x, y;
    cin >> n >> x >> y;
    long long res = 0;
    if (n % 3 == 0) {
         cout << max(n * n / 3 * x, n * n / 4 * y);
    } else {
        cout << max({n * n / 4 * y, n * n / 3 * x, n * n / 3 * x - x + y});
    }
    return 0;
}