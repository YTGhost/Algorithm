#include <iostream>
using namespace std;

const int N = 100010;
char e[N];
int ne[N];
bool st[N];

int main()
{
    int start, end, n;
    cin >> start >> end >> n;
    for(int i = 0; i < n; i++) {
        int address, next;
        char data;
        cin >> address >> data >> next;
        e[address] = data;
        ne[address] = next;
    }
    for(int i = start; i != -1; i = ne[i]) {
        st[i] = true;
    }
    bool t = false;
    for(int i = end; i != -1; i = ne[i]) {
        if(st[i]) {
            printf("%05d", i);
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}