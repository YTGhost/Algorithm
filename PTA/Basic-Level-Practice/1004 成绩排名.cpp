#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Person
{
    string name, id;
    int grade;
};

int main()
{
    int n;
    cin >> n;
    vector<Person> a(n);
    for(int i = 0; i < n; i++)
    {
        string name, id;
        int grade;
        cin >> name >> id >> grade;
        a[i] = {name, id, grade};
    }
    sort(a.begin(), a.end(), [](Person& b, Person& c) {
        return b.grade > c.grade;
    });
    cout << a[0].name << " " << a[0].id << endl;
    cout << a[n-1].name << " " << a[n-1].id << endl;
    return 0;
}