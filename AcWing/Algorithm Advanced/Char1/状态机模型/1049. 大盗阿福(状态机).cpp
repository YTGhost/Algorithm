#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int f[N][2], a[N];

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
        f[1][1] = a[1];
        for(int i = 2; i <= n; i++)
        {
            f[i][0] = max(f[i-1][0], f[i-1][1]);
            f[i][1] = f[i-1][0] + a[i];
        }
        cout << max(f[n][0], f[n][1]) << endl;
    }
    return 0;
}