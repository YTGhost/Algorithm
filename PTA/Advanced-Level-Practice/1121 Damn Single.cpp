#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int N = 50010;
const int M = 10010;

struct couple {
    int a, b;
}c[N];

int res[M];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c[i].a >> c[i].b;
    }
    unordered_set<int> s;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int id;
        cin >> id;
        s.insert(id);
    }
    for(int i = 0; i < n; i++) {
        int a = c[i].a, b = c[i].b;
        if(s.count(a) && s.count(b)) {
            s.erase(a);
            s.erase(b);
        }
    }
    
    int k = 0;
    for(auto id : s) {
        res[k++] = id;
    }
    sort(res, res + k);
    cout << k << endl;
    for(int i = 0; i < k; i++)
        if(i == k-1) printf("%05d\n", res[i]);
        else printf("%05d ", res[i]);
    return 0;
}