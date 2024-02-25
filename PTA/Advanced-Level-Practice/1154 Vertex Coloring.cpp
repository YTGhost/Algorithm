#include <iostream>
#include <unordered_set>
using namespace std;

int n, m;
const int N = 10010;
struct edge {
    int a;
    int b;
}edges[N];
int nodes[N];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b;
    }
    int k;
    cin >> k;
    while(k--) {
        for(int i = 0; i < n; i++) {
            cin >> nodes[i];
        }
        bool flag = true;
        int sum = 0;
        for(int i = 0; i < m; i++) {
            if(nodes[edges[i].a] == nodes[edges[i].b]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            unordered_set<int> s;
            for(int i = 0; i < n; i++) s.insert(nodes[i]);
            printf("%d-coloring\n", s.size());
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}