#include <iostream>
#include <set>
using namespace std;

const int N = 10010;
int a[N];

int main()
{
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int sum = 0;
        while(x)
        {
            sum += x % 10;
            x /= 10;
        }
        s.insert(sum);
    }
    cout << s.size() << endl;
    set<int>::iterator iter = s.begin();
    while(iter != s.end())
    {
        if(iter == --s.end()) cout << *iter;
        else cout << *iter << " ";
        iter++;
    }
    cout << endl;
    return 0;
}