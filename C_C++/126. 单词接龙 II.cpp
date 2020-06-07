class Solution {
public:
    unordered_map<string, int> wordId;
    vector<string> idToWord;
    vector<vector<int>> edge;
    vector<vector<string>> ans;

    // 检查能否从一个单词变成另一个单词
    bool check(const string& str1, const string& str2){
        int diff = 0;
        for(int i = 0; i < str1.length(); i++)
        {
            if(str1[i] != str2[i]){
                if(++diff >= 2) return false;
            }
        }
        return true;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // 给单词设定id
        int id = 0;
        for(auto word : wordList)
        {
            if(!wordId.count(word)){
                wordId[word] = id++;
                idToWord.push_back(word);
            }
        }

        // 如果表中没有终点，显然转换不了
        if(!wordId.count(endWord)) return {};

        // 表中没有起点的话，加入起点
        if(!wordId.count(beginWord)){
            wordId[beginWord] = id++;
            idToWord.push_back(beginWord);
        }

        edge.resize(id);
        // 建图
        for(int i = 0; i < id; i++)
            for(int j = i+1; j < id; j++)
            {
                if(check(idToWord[i], idToWord[j])){
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        
        queue<vector<int>> q;
        int dest = wordId[endWord];
        vector<int> dist(id, INT_MAX);
        q.push(vector<int> {wordId[beginWord]});
        dist[wordId[beginWord]] = 0;
        while(!q.empty())
        {
            vector<int> t = q.front();
            int back = t.back();
            q.pop();
            if(back == dest){
                vector<string> tmp;
                for(int index : t) tmp.push_back(idToWord[index]);
                ans.push_back(tmp);
            }else{
                for(int i = 0; i < edge[back].size(); i++)
                {
                    int to = edge[back][i];
                    if(dist[back] + 1 <= dist[to])
                    {
                        dist[to] = dist[back] + 1;
                        vector<int> tmp(t);
                        tmp.push_back(to);
                        q.push(tmp);
                    }
                }
            }
        }
        return ans;
    }
};