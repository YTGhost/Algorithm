#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int x = n - (k - 1);
        if(x > 0 && x % 2 == 1) {
            cout << "YES" << endl;
            for(int i = 0; i < k - 1; i++) {
                cout << 1 << " ";
            }
            cout << x << endl;
            continue;
        }
        x = n - 2 * (k - 1);
        if(x > 0 && x % 2 == 0) {
            cout << "YES" << endl;
            for(int i = 0; i < k - 1; i++) {
                cout << 2 << " ";
            }
            cout << x << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}