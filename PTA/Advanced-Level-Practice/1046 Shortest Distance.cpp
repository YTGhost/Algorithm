#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) 
    {
        int x;
        cin >> x;
        a[i] = x + a[i-1];
    }
    int x;
    cin >> x;
    a[n] = x;
    int m;
    cin >> m;
    while(m--)
    {
        int b, c;
        cin >> b >> c;
        if(b > c) swap(b, c);
        if(b == c) cout << 0 << endl;
        else cout << min(a[c-1] - a[b-1], a[b-1] + a[n] + a[n-1] - a[c-1]) << endl;
    }
    return 0;
}