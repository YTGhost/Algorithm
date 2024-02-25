#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int pre, cur, res = 0;
    cin >> pre >> cur;
    res = max(res, abs(cur-pre));
    
    for(int i = 0; i < n-2; i++)
    {
        pre = cur;
        cin >> cur;
        res = max(res, abs(cur-pre));
    }
    cout << res << endl;
    return 0;
}