class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int res = 0;
        int sum = accumulate(energy.begin(), energy.end(), 0);
        if(initialEnergy <= sum) {
            res += sum - initialEnergy + 1;
        }
        for(auto e : experience) {
            if(initialExperience > e) {
                initialExperience += e;
            } else {
                int t = e - initialExperience + 1;
                initialExperience = 2 * e + 1;
                res += t;
            }
        }
        return res;
    }
};