#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int n)
{
    if(n < 2) return false;
    for(int i = 2; i <= n / i; i++)
        if(n % i == 0) return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(isPrime(x)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}