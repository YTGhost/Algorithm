#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int res = n;
    for(int i = 0; i < n; i++) {
        if(a[i] > res) break;
        res--;
    }
    cout << res << endl;
    return 0;
}