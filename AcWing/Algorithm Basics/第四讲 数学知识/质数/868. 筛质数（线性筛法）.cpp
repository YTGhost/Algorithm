#include <iostream>
using namespace std;

const int N = 1000010;
int n;
int primes[N], cnt;
bool st[N];

void get_prime(int n)
{
    for(int i = 2; i <= n; i++) {
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main()
{
    cin >> n;
    get_prime(n);
    cout << cnt << endl;
    return 0;
}