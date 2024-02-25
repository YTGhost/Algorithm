#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 10010;
int n, k;
unordered_map<int, int> m;
int st[N];

bool isPrime(int x)
{
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int id;
        cin >> id;
        m[id] = i;
    }
    cin >> k;
    for(int i = 0; i < k; i++) {
        int id;
        cin >> id;
        printf("%04d: ", id);
        if(st[id]) {
            printf("Checked\n");
            continue;
        }
        if(m.count(id)) {
            int idx = m[id];
            if(idx == 1) {
                printf("Mystery Award\n");
            } else if(isPrime(idx)) {
                printf("Minion\n");
            } else {
                printf("Chocolate\n");
            }
            st[id] = 1;
        } else {
            printf("Are you kidding?\n");
        }
    }
    return 0;
}