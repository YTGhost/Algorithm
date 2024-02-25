#include <iostream>
using namespace std;

const int N = 20000000;
int a[N];

int main()
{
    int m, n, maxNum = 0;
    cin >> m >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            maxNum = max(maxNum, x);
            a[x]++;
        }
    int t = 0, res;
    for(int i = 0; i <= maxNum ; i++) {
        if(a[i] > t) {
            t = a[i];
            res = i;
        }
    }
    cout << res << endl;
    return 0;
}