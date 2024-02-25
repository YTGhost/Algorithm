#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int res = 0, temp = 0;
    for(int i = 1; i <= 7; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a + b > 8) {
            if(temp == 0 || a + b > temp) temp = a + b, res = i;
        }
    }
    cout << res << endl;
    return 0;
}