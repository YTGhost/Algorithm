class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        vector<int> dist(n);
        for(int i = 0; i < n - 1; i++) {
            dist[i + 1] += dist[i] + travel[i];
        }
        int finalM = 0, finalP = 0, finalG = 0;
        int cntM = 0, cntP = 0, cntG = 0;
        for(int i = 0; i < n; i++) {
            for(auto c : garbage[i]) {
                if(c == 'M') {
                    finalM = i;
                    cntM++;
                } else if(c == 'P') {
                    finalP = i;
                    cntP++;
                } else {
                    finalG = i;
                    cntG++;
                }
            }
        }
        return dist[finalM] + cntM + dist[finalP] + cntP + dist[finalG] + cntG;
    }
};