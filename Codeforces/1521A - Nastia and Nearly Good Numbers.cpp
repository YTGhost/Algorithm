#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        long long a, b;
        cin >> a >> b;
        if(b == 1) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << a << " " << a * b << " " << (b + 1) * a << endl;
    }
    return 0;
}