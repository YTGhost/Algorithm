#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < 9; i++) {
        int x;
        cin >> x;
        sum1 += x;
    }
    for(int i = 0; i < 8; i++) {
        int x;
        cin >> x;
        sum2 += x;
    }
    cout << sum1 - sum2 + 1 << endl;
    return 0;
}