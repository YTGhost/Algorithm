#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 2; i <= n; i++) a[i] += a[i-1];
    while(m--)
    {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l-1] << endl;
    }
    return 0;
}