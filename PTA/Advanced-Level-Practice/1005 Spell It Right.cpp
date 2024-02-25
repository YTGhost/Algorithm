#include <iostream>
#include <algorithm>
using namespace std;

string table[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string getStr(char c)
{
    return table[c - '0'];
}

int main()
{
    string n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n.size(); i++)
    {
        sum += n[i] - '0';
    }
    string str = to_string(sum);
    for(int i = 0; i < str.size()-1; i++)
        cout << getStr(str[i]) << " ";
    cout << getStr(str[str.size()-1]) << endl;
    return 0;
}