#include <iostream>
using namespace std;

int main()
{
    int n;
    char c;
    cin >> n >> c;
    int row = n % 2 == 0 ? n / 2 : n / 2 + 1;
    for(int i = 0; i < n; i++) cout << c;
    cout << endl;
    row -= 2;
    for(int i = 0; i < row; i++)
    {
        cout << c;
        for(int j = 0; j < n-2; j++) cout << " ";
        cout << c << endl;
    }
    for(int i = 0; i < n; i++) cout << c;
    return 0;
}