#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];
int n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int s1 = 0, s2 = 0;
    for(int i = 0; i < n / 2; i++) s1 += a[i];
    for(int i = n / 2; i < n; i++) s2 += a[i];
    printf("%d %d", n % 2, s2 - s1);
    return 0;
}