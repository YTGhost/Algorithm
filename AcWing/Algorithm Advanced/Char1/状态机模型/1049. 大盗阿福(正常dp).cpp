#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int f[N], a[N];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        f[1] = a[1];
        f[2] = max(a[1], a[2]);
        for(int i = 3; i <= n; i++)
            f[i] = max(f[i-1], f[i-2] + a[i]);
        cout << f[n] << endl;
    }
    return 0;
}