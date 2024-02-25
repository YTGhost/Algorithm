#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student 
{
    string id;
    int grade, finalRank, locationNumber, localRank;
    
    bool operator< (const Student& t) const {
        if(grade != t.grade) return grade > t.grade;
        else return id < t.id;
    }
};

int main()
{
    int n, total = 0;
    cin >> n;
    vector<Student> allStudents;
    
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        total += k;
        vector<Student> students;
        for(int j = 0; j < k; j++) {
            string id;
            int grade, finalRank = 0, locationNumber = i, localRank = 0;
            cin >> id >>grade;
            students.push_back({id, grade, finalRank, locationNumber, localRank});
        }
        sort(students.begin(), students.end());
        int rank = 1, pre = -1;
        for(int j = 0; j < students.size(); j++) {
            students[j].localRank = students[j].grade != pre ? rank : students[j-1].localRank;
            pre = students[j].grade;
            rank++;
            allStudents.push_back(students[j]);
        }
    }
    
    sort(allStudents.begin(), allStudents.end());
    int rank = 1, pre = -1;
    for(int i = 0; i < allStudents.size(); i++) {
        allStudents[i].finalRank = allStudents[i].grade != pre ? rank : allStudents[i-1].finalRank;
        pre = allStudents[i].grade;
        rank++;
    }
    cout << total << endl;
    for(auto s : allStudents) {
        cout << s.id << " " << s.finalRank << " " << s.locationNumber << " " << s.localRank << endl;
    }
    return 0;
}