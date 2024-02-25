#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1001;
int a[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= 1000; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    int cnt = 0;
    for(int i = 1; i <= 1000; i++)
        if(a[i]) a[cnt++] = i;
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}