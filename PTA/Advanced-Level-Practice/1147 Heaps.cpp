#include <iostream>
using namespace std;

const int N = 1010;
int n, m;
int h[N];

void dfs(int u, int& isMax, int& isMin)
{
    if(2 * u <= n) {
        if(h[u] > h[2 * u]) isMax = 1;
        else isMin = 1;
        dfs(2 * u, isMax, isMin);
    }
    if(2 * u + 1 <= n) {
        if(h[u] > h[2 * u + 1]) isMax = 1;
        else isMin = 1;
        dfs(2 * u + 1, isMax, isMin);
    }
}

void print_post(int u, int& flag)
{
    if(2 * u <= n) print_post(2 * u, flag);
    if(2 * u + 1 <= n) print_post(2 * u + 1, flag);
    if(flag) printf("%d", h[u]), flag = 0;
    else printf(" %d", h[u]);
}

int main()
{
    cin >> m >> n;
    while(m--) {
        for(int i = 1; i <= n; i++) cin >> h[i];
        int isMax = 0, isMin = 0;
        dfs(1, isMax, isMin);
        if(isMax == 1 && isMin == 1) {
            cout << "Not Heap" << endl;
        } else if(isMax == 1) {
            cout << "Max Heap" << endl;
        } else {
            cout << "Min Heap" << endl;
        }
        int isFirst = 1;
        print_post(1, isFirst);
        cout << endl;
    }
}