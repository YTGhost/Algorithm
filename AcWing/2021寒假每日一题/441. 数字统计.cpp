#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int l, r, res = 0;
    cin >> l >> r;
    for(int i = l; i <= r; i++)
        for(int j = i; j; j /= 10)
            if(j % 10 == 2) res++;
    cout << res << endl;
    return 0;
}