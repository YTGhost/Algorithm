class Solution {
public:
    int hash[1000];
    int numRabbits(vector<int>& answers) {
        int res = 0;    
        sort(answers.begin(), answers.end());
        for(int i = 0; i < answers.size(); i++)
        {
            if(!answers[i]) {
                res++;
            } else if(!hash[answers[i]]) {
                hash[answers[i]] = answers[i];
                res += answers[i] + 1;
            } else {
                hash[answers[i]]--;
            }
        }
        return res;
    }
};