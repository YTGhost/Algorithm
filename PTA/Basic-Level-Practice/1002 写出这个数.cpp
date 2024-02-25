#include <iostream>
using namespace std;

string a[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{
    string str;
    cin >> str;
    int sum = 0;
    for(auto c : str)
        sum += c - '0';
    string res = to_string(sum);
    int len = res.length();
    for(int i = 0; i < len-1; i++)
        cout << a[res[i] - '0'] << " ";
    cout << a[res[len-1] - '0'] << endl;
    return 0;
}