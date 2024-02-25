#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int b[N];

void insert(int l, int r, int c)
{
    b[l] += c;
    b[r+1] -= c;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        insert(i, i, x);
    }
    for(int i = 0; i < m; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }
    printf("%d", b[1]);
    for(int i = 2; i <= n; i++) {
        b[i] += b[i-1];
        printf(" %d", b[i]);
    }
    return 0;
}