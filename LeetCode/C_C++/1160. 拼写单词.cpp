class Solution {
public:
    int a[26];
    int countCharacters(vector<string>& words, string chars) {
        int sum = 0;
        for(int i = 0; i < chars.length(); i++)
        {
            int index = chars[i] - 'a';
            a[index]++;
        }
        for(auto word : words)
        {
            int b[26];
            memcpy(b, a, 26 * sizeof(int));
            int i;
            for(i = 0; i < word.length(); i++)
            {
                int index = word[i] - 'a';
                if(b[index] == 0)   break;
                b[index]--;
            }
            if(i == word.length()){
                sum += i;
            }
        }
        return sum;
    }
};