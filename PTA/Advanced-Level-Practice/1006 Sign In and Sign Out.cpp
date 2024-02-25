#include <iostream>
using namespace std;

int main()
{
    int m;
    cin >> m;
    string openId, closeId;
    string openTime, closeTime;
    for(int i = 0; i < m; i++)
    {
        string id, signIn, signOut;
        cin >> id >> signIn >> signOut;
        if(!i || signIn < openTime) {
            openTime = signIn;
            openId = id;
        }
        
        if(!i || signOut > closeTime) {
            closeTime = signOut;
            closeId = id;
        }
    }
    cout << openId << " " << closeId << endl;
    return 0;
}