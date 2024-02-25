/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/

// 2021/05/01 每日一题
class Solution {
public:
    int res;
    void dfs(vector<Employee*> &employees, int id) {
        for(auto e : employees)
        {
            if(e->id == id) {
                res += e->importance;
                for(auto s : e->subordinates) {
                    dfs(employees, s);
                }
            }
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        dfs(employees, id);
        return res;
    }
};

class Solution {
public:
    int sum = 0;
    map<int, Employee*> m;
    int getImportance(vector<Employee*> employees, int id) {
        for(auto employee : employees){
            m[employee->id] = employee;
        }
        dfs(id);
        return sum;
    }
    void dfs(int id){
        Employee* temp = m.find(id)->second;
        sum += temp->importance;
        for(int i = 0; i < temp->subordinates.size(); i++)
        {
            dfs(temp->subordinates[i]);
        }
    }
};