class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> freqMin(26, 101);
        vector<int> freq(26, 0);
        vector<string> res;
        for(int i = 0; i < A.size(); i++)
        {
            fill(freq.begin(), freq.end(), 0);
            for(auto c : A[i])
                freq[c - 'a']++;
            for(int j = 0; j < 26; j++)
                freqMin[j] = min(freqMin[j], freq[j]);
        }

        for(int i = 0; i < 26; i++)
            for(int j = 0; j < freqMin[i]; j++)
            {
                res.emplace_back(1, 'a' + i);
            }
        return res;
    }
};