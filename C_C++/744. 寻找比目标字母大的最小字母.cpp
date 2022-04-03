class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size();
        int n = letters.size();
        while(l < r) {
            int mid = l + r >> 1;
            if(letters[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return letters[l % n];
    }
};

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size()-1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(letters[mid] > target) r = mid;
            else l = mid+1;
        }
        return target < letters[l] ?  letters[l] : letters[0];
    }
};