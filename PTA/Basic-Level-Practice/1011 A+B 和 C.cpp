#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        long a, b, c;
        long sum;
        cin >> a >> b >> c;
        cout << "Case #" << i << ": ";
        sum = a + b;
        if(sum > c) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}