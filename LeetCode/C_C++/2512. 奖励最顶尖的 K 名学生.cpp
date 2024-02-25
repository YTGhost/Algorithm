class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string, int> hash;
        for(auto &word : positive_feedback) {
            hash[word] = 3;
        }
        for(auto &word : negative_feedback) {
            hash[word] = -1;
        }
        vector<vector<int>> temp;
        for(int i = 0; i < report.size(); i++) {
            stringstream ss;
            string w;
            int score = 0;
            ss << report[i];
            while(ss >> w) {
                if(hash.count(w)) {
                    score += hash[w];
                }
            }
            temp.push_back({-score, student_id[i]});
        }
        sort(temp.begin(), temp.end());
        vector<int> res(k);
        for(int i = 0; i < k; i++) {
            res[i] = temp[i][1];
        }
        return res;
    }
};