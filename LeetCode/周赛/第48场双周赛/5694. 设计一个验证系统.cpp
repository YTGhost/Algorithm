class AuthenticationManager {
public:
    int toLive;
    unordered_map<string, int> m;
    AuthenticationManager(int timeToLive) {
        toLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        m[tokenId] = currentTime + toLive;
    }
    
    void renew(string tokenId, int currentTime) {
        int pre = m[tokenId];
        if(pre <= currentTime) return;
        m[tokenId] = currentTime + toLive;
    }
    
    int countUnexpiredTokens(int currentTime) {
        unordered_map<string, int> ::iterator it;
        it = m.begin();
        int res = 0;
        while(it != m.end()) {
            if(it->second > currentTime) res++;
            it++;
        }
        return res;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */