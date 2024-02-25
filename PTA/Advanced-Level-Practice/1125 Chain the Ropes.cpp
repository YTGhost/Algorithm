#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 10010;
int n;
int a[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    double res = a[0];
    for(int i = 1; i < n; i++) {
        res /= 2;
        res += a[i] / 2.0;
    }
    cout << floor(res) << endl;
    return 0;
}