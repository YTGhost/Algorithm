#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    int n1 = (n + 2) / 3;
    int n2 = n + 2 - 2 * n1;
    for(int i = 0; i < n1-1; i++) {
        string out = str[i] + string(n2-2, ' ') + str[str.size() - 1 - i];
        cout << out << endl;
    }
    string out = str.substr(n1-1, n2);
    cout << out << endl;
    return 0;
}