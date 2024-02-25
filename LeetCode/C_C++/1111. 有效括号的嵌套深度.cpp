class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> a;
        for(int i = 0; i < seq.length(); i++)
        {
            a.push_back(seq[i] == '(' ? i & 1 : ((i+1) & 1));
        }
        return a;
    }
};