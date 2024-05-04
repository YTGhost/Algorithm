#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a; 
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        int value = INT_MIN;
        int res;
        for(int y = 1; y < x; y++) {
            int sum = gcd(x, y) + y;
            if(sum > value) {
                value = sum;
                res = y;
            }
        }
        cout << res << endl;
    }
    return 0;
}