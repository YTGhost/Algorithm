#include <iostream>
using namespace std;

typedef long long LL;

bool isPrime(int x)
{
    if(x == 1) return false;
    
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

bool check(int n, int d)
{
    if(!isPrime(n)) return false;
    
    LL r = 0;
    while(n) {
        r = r * d + n % d;
        n /= d;
    }
    
    return isPrime(r);
}

int main()
{
    int n, d;
    while(cin >> n >> d, n >= 1) {
        if(check(n, d)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}