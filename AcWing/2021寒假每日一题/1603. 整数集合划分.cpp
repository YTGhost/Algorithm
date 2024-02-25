#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N], n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    if(n % 2) cout << 1 << " ";
    else cout << 0 << " ";

    sort(a, a + n);
    int s1 = 0, s2 = 0;
    for(int i = 0; i < n / 2; i++) s1 += a[i];
    for(int i = n / 2; i < n; i++ ) s2 += a[i];
    cout << s2 - s1 << endl;
    return 0;
}