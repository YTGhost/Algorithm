#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    unordered_set<int> s;
    int v1 = 1e9, v2;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int y = m - x;
        if(s.count(y)) {
            if(x > y) swap(x, y);
            if(x < v1) v1 = x, v2 = y;
        } else {
            s.insert(x);
        }
    }
    if(v1 == 1e9) cout << "No Solution" << endl;
    else cout << v1 << " " << v2 << endl;
    return 0;
}