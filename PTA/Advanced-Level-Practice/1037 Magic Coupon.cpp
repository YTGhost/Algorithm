#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N], b[N];
int c, p;

int main()
{
    cin >> c;
    for(int i = 0; i < c; i++) cin >> a[i];
    cin >> p;
    for(int i = 0; i < p; i++) cin >> b[i];
    
    sort(a, a + c);
    sort(b, b + p);
    
    int res = 0;
    
    for(int i = 0, j = 0; i < c && j < p && a[i] < 0 && b[j] < 0; i++, j++) {
        res += a[i] * b[j];
    }
    
    for(int i = c - 1, j = p - 1; i >= 0 && j >= 0 && a[i] > 0 && b[j] > 0; i--, j--) {
        res += a[i] * b[j];
    }
    cout << res << endl;
    return 0;
}