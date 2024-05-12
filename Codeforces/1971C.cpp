#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a > b) {
            swap(a, b);
        }
        if(c > d) {
            swap(c, d);
        }
        if(c <= a && c >= 1 || c >= b && c <= 12) {
            if(d >= a && d <= b) {
                cout << "YES" << endl;
                continue;
            }
        }
        if(d <= a && d >= 1 || d >= b && d <= 12) {
            if(c >= a && c <= b) {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}