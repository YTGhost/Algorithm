#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student {
    string name, id;
    int score;
};

int main()
{
    int n;
    cin >> n;
    vector<student> students;
    for(int i = 0; i < n; i++) {
        string name, id;
        int score;
        cin >> name >> id >> score;
        students.push_back({name, id, score});
    }
    int l, r;
    cin >> l >> r;
    int sign = false;
    sort(students.begin(), students.end(), [](student& a, student& b) {
        return a.score > b.score;
    });
    for(auto student : students) {
        if(student.score >= l && student.score <= r) {
            sign = true;
            cout << student.name << " " << student.id << endl;
        }
    }
    if(!sign) cout << "NONE" << endl;
    return 0;
}