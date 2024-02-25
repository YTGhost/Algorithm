#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

int main()
{
    int n, p;
    cin >> n >> p;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int res = 0;
    for(int i = 0, j = 0; i < n; i++)
    {
        while((long long)a[j] * p < a[i]) j++;
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}