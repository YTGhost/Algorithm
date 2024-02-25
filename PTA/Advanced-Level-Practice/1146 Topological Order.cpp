#include <iostream>
using namespace std;

int n, m;
const int N = 1010, M = 10010;

struct edge {
    int a;
    int b;
} edges[M];

int nodes[N];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> edges[i].a >> edges[i].b;
    
    int k;
    cin >> k;
    bool isFirst = true;
    for(int idx = 0; idx < k; idx++) {
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            nodes[x] = i;
        };
        bool flag = true;
        for(int i = 0; i < m; i++) {
            if(nodes[edges[i].a] > nodes[edges[i].b]) {
                flag = false;
                break;
            }
        }
        if(!flag) {
            if(isFirst) {
                cout << idx;
                isFirst = false;
            } else {
                cout << " " << idx;
            }
        }
    }
    return 0;
}