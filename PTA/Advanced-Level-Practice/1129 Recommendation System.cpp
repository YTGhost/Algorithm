#include <iostream>
#include <algorithm>
using namespace std;

const int N = 50010;
int cnt[N];
int topK[11];

int main()
{
    int n, m;
    cin >> n >> m;
    int k = 0;
    for(int i = 0; i < n; i++) {
        int id;
        cin >> id;
        if(i) {
            printf("%d:", id);
            for(int j = 0; j < k; j++) printf(" %d", topK[j]);
            cout << endl;
        }
        cnt[id]++;
        bool sign = false;
        for(int j = 0; j < k; j++) {
            if(topK[j] == id) {
                sign = true;
                break;
            }
        }
        if(!sign) topK[k++] = id;
        sort(topK, topK + k, [](int x, int y) {
            if(cnt[x] != cnt[y]) return cnt[x] > cnt[y];
            return x < y;
        });
        k = min(k, m);
    }
    return 0;
}