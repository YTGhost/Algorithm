#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
using namespace std;

const int N = 55;

unordered_set<int> s[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        while(m--)
        {
            int a;
            cin >> a;
            s[i].insert(a);
        }
    }
    int k;
    cin >> k;
    while(k--)
    {
        int a, b;
        cin >> a >> b;
        int nc = 0;
        for(auto x : s[a]) nc += s[b].count(x);
        int nt = s[a].size() + s[b].size() - nc;
        printf("%.1lf%%\n", (double)nc / nt * 100);
    }
    return 0;
}