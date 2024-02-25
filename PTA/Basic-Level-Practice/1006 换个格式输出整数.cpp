#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(3);
    for(int i = 0; i < 3; i++)
    {
        a[i] = n % 10;
        n /= 10;
    }
    string res = "";
    for(int i = 0; i < a[2]; i++)
        res += 'B';
    for(int i = 0; i < a[1]; i++)
        res += 'S';
    for(int i = 1; i <= a[0]; i++)
        res += to_string(i);
    cout << res << endl;
    return 0;
}