#include <iostream>

using namespace std;

typedef long long LL;

int qmi(int a, int b, int p)
{
    int res = 1;
    while(b)
    {
        if(b&1) res = (LL)res * a % p;
        b >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main()
{
    int a, b, p, n, res;
    cin >> n;
    while(n--)
    {
        cin >> a >> b >> p;
        res = qmi(a, b, p);
        cout << res << endl;
    }
    return 0;
}