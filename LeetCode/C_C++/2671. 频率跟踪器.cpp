class FrequencyTracker {
public:
    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;
    FrequencyTracker() {

    }
    
    void add(int number) {
        if(mp1.count(number)) {
            mp2[mp1[number]]--;
            if(mp2[mp1[number]] == 0) {
                mp2.erase(mp1[number]);
            }
        }
        mp1[number]++;
        mp2[mp1[number]]++;
    }
    
    void deleteOne(int number) {
        if(mp1.count(number)) {
            mp2[mp1[number]]--;
            if(mp2[mp1[number]] == 0) {
                mp2.erase(mp1[number]);
            }
            mp1[number]--;
            mp2[mp1[number]]++;
            if(mp1[number] == 0) {
                mp1.erase(number);
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return mp2.count(frequency);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */