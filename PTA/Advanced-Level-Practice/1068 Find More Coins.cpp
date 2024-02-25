#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int a[N];
bool f[N][105];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1, greater<int>());
    
    f[0][0] = true;
    
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++)
        {
            f[i][j] = f[i-1][j];
            if(j >= a[i]) f[i][j] |= f[i-1][j-a[i]]; 
        }
    bool isFirst = true;
    if(f[n][m]) {
        while(n)
        {
            if(m >= a[n] && f[n-1][m-a[n]]) {
                if(isFirst) isFirst = false;
                else cout << " ";
                cout << a[n];
                m -= a[n];
            }
            n--;
        }
    } else {
        cout << "No Solution" << endl;
    }
    return 0;
}