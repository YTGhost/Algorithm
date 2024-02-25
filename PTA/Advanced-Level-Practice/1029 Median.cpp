#include <iostream>
using namespace std;

const int N = 200010;

int a[N], b[N], c[2*N];

int main()
{
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i];
    int i = 0, j = 0, k = 0;
    while(i < n && j < m)
        if(a[i] <= b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    while(i < n) c[k++] = a[i++];
    while(j < m) c[k++] = b[j++];
    cout << c[(n + m - 1) >> 1] << endl;
    return 0;
}