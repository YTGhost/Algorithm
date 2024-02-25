#include <iostream>
using namespace std;

int convert(string x)
{
    int sum = 1;
    for(auto c : x)
        sum *= c - 'A' + 1;
    return sum % 47;
}

int main()
{
    string a, b;
    cin >> a >> b;
    int c, d;
    c = convert(a);
    d = convert(b);
    if(c == d) cout << "GO" << endl;
    else cout << "STAY" << endl;
    return 0;
}