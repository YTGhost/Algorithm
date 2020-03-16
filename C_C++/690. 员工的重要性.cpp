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