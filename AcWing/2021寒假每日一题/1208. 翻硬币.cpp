#include <iostream>
using namespace std;

string a, b;

void turn(int x)
{
    a[x] == '*' ? a[x] = 'o' : a[x] = '*'; 
}

int main()
{
    int res = 0;
    cin >> a >> b;
    
    for(int i = 0; i + 1 < a.size(); i++)
    {
        if(a[i] != b[i])
        {
            turn(i), turn(i+1);
            res++;
        }
    }
    cout << res << endl;
    return 0;
}