#include <iostream>
using namespace std;

const int N = 10010;
int k, n, m;
int h[N];

int is_prime(int x) 
{
    if(x == 1) return false;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int find(int x)
{
    int t = x % k;
    for(int i = 0; i < k; i++) {
        int j = (t + i * i) % k;
        if(!h[j]) {
            h[j] = x;
            return j;
        }
    }
    return -1;
}

int findCount(int x)
{
    int res = 1;
    int t = x % k;
    for(int i = 0; i < k; i++, res++) {
        int j = (t + i * i) % k;
        if(!h[j] || h[j] == x) return res;
    }
    return res;
}

int main()
{
    cin >> k >> n >> m;
    while(!is_prime(k)) k++;
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int t = find(x);
        if(t == -1) {
            printf("%d cannot be inserted.\n", x);
        }
    }
    
    int sum = 0;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        sum += findCount(x);
    }
    printf("%.1lf", (double)sum / m);
    return 0;
}