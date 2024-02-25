#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = 0;
    while(n)
    {
        res = res * 10 + n % 10;
        n /= 10;
    }
    cout << res << endl;
    return 0;
}