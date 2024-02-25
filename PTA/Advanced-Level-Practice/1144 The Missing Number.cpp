#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 100010;


int main()
{
    int n;
    cin >> n;
    unordered_set<int> s;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    int res = 1;
    while(s.count(res)) res++;
    cout << res << endl;
    return 0;
}