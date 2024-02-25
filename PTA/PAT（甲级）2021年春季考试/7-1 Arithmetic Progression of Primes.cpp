#include <iostream>
using namespace std;

const int N = 100010, M = 15;
int primes[N], st[N], cnt;
int n, m;
int diff;
int res[M];

void getPrimes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main()
{
    cin >> n >> m;
    getPrimes(m);
    if(n != 1) {
        for(int i = 0; i < cnt; i++) {
            int a = primes[i];
            for(int j = (m - a) / (n - 1); j > 1; j--) {
                bool flag = true;
                for(int k = 1; k < n; k++) {
                    int x = a + j * k;
                    if(st[x]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    if(j >= diff) {
                        for(int i = 0; i < n; i++) res[i] = a + j * i; 
                        diff = j;
                    }
                    break;
                }
            }
        }
    }
    if(diff) {
        printf("%d", res[0]);
        for(int i = 1; i < n; i++) printf(" %d", res[i]);
    } else {
        for(int i = m; i; i--) {
            if(!st[i]) {
                printf("%d", i);
                break;
            }
        }
    }
    return 0;
}