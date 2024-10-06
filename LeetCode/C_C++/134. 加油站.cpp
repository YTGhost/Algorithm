class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0, s = 0, minS = 0;
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            s += gas[i] - cost[i];
            if (s < minS) {
                minS = s;
                res = i + 1;
            }
        }
        return s < 0 ? -1 : res;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int run = 0, rest = 0, start = 0;
        for(int i = 0; i < gas.size(); i++) {
            run += gas[i] - cost[i];
            rest += gas[i] - cost[i];
            if(run < 0) {
                start = i + 1;
                run = 0;
            }
        }
        return rest < 0 ? -1 : start;
    }
};