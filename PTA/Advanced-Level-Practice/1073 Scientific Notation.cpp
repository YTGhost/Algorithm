#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s[0] == '-') printf("-");
    int k = s.find('E');
    string a = s[1] + s.substr(3, k-3);
    int b = stoi(s.substr(k + 1));
    b++;
    string res;
    if(b <= 0) res = "0." + string(-b, '0') + a;
    else if(b >= a.size()) res = a + string(b - a.size(), '0');
    else res = a.substr(0, b) + "." + a.substr(b);
    cout << res << endl;
    return 0;
}