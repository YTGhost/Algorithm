#include <iostream>
using namespace std;

const int N = 1000010;
int n;
int primes[N], cnt;
bool st[N];

void get_prime(int n)
{
    for(int i = 2; i <= n; i++) {
        if(st[i]) continue;
        primes[cnt++] = i;
        for(int j = i + i; j <= n; j += i) {
            st[j] = true;
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