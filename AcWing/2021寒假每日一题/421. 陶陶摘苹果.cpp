#include <iostream>
using namespace std;
const int N = 10;
int a[N];

int main()
{
    int h, res = 0;
    for(int i = 0; i < 10; i++) cin >> a[i];
    cin >> h, h += 30;
    for(int i = 0; i < 10; i++)
        if(a[i] <= h) res++;
    cout << res << endl;
    return 0;
}