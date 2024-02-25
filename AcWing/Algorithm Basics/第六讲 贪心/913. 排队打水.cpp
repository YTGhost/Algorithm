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
    long long res = 0;
    for(int i = 0; i < n; i++) {
        res += (n - i - 1) * a[i];
    }
    cout << res << endl;
    return 0;
}