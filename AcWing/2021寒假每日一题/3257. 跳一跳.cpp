#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int x, sum = 0, pre = 1;
    while(cin >> x && x)
    {
        if(x == 2) {
            if(pre == 1) pre = 2;
            else pre += 2;
        } else pre = 1;
        sum += pre;
    }
    cout << sum << endl;
}