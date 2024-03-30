// s = cf * k
// find smallest cf * k >= n, so cf = (n + k - 1) / k
// if ai is maximum element in a is minimum possible,
// ai = (cf * k + n - 1) / n

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long cf = (n + k - 1) / k;
        k *= cf;
        cout << (k + n - 1) / n << endl;
    }
    return 0;
}