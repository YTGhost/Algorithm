#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];
int h[1010];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n, greater<int>());
    int sign = 0;
    int v1, v2;
    for(int i = 0; i < n; i++)
    {
        if(h[m - a[i]]) {
            v1 = a[i], v2 = m - a[i];
            sign = 1;
        }
        h[a[i]] = 1;
    }
    if(!sign) cout << "No Solution" << endl;
    else cout << v1 << " " << v2 << endl;
    return 0;
}