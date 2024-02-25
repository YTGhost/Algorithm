#include <iostream>
using namespace std;

const int N = 1000010;
int primes[N], cnt;
bool st[N];
int n;

void getPrime(int n)
{
    for(int i = 2; i <= n; i++) {
        if(st[i]) continue;
        primes[cnt++] = i;
        for(int j = i + i; j <= n; j += i) {
            st[j] = true;
        }
    }
}

bool isPrime(int n)
{
    if(n < 2) return false;
    for(int i = 2; i <= n / i; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main()
{
    cin >> n;
    if(isPrime(n)) {
        if(isPrime(n - 6)) {
            printf("Yes\n");
            printf("%d\n", n - 6);
        } else if(isPrime(n + 6)) {
            printf("Yes\n");
            printf("%d\n", n + 6);
        } else {
            printf("No\n");
            int i = n + 1;
            while(!isPrime(i) || !isPrime(i + 6) && !isPrime(i - 6)) i++;
            printf("%d\n", i);
        }
    } else {
        printf("No\n");
        int i = n + 1;
        while(!isPrime(i) || !isPrime(i + 6) && !isPrime(i - 6)) i++;
        printf("%d\n", i);
    }
}