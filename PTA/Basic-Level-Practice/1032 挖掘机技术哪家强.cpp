#include <iostream>
using namespace std;

const int N = 100010;
int s[N];

int main()
{
    int n;
    int maxNum, maxGrade = 0;
    cin >> n;
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        s[a] += b;
        if(s[a] > maxGrade) maxNum = a, maxGrade = s[a];
    }
    cout << maxNum << " " << maxGrade << endl;
    return 0;
}