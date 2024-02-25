#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 10010;

int l[N], r[N];
int n, m;

void judge(unordered_set<int> &s)
{
    for(int i = 0; i < n; i++)
    {
        if(s.count(l[i]) && s.count(r[i])) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        l[i] = a, r[i] = b;
    }
    while(m--)
    {
        unordered_set<int> s;
        int k;
        cin >> k;
        while(k--)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        judge(s);
    }
    return 0;
}