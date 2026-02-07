class Solution {
public:
    unordered_map<string, vector<string>> parent;
    vector<vector<string>> ans;
    vector<string> path;

    void bfs(string beginWord, string endWord, unordered_set<string>& dict) {
        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord); 

        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> levelVisited;

            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                for (int j = 0; j < word.size(); j++) {
                    string temp = word;

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (temp[j] == ch) continue;
                        temp[j] = ch;

                        if (dict.count(temp)) {

                            if (!visited.count(temp)) {
                                if (temp == endWord)
                                    found = true;

                                if (!levelVisited.count(temp)) {
                                    q.push(temp);
                                    levelVisited.insert(temp);
                                }

                                parent[temp].push_back(word);
                            }
                        }
                    }
                }
            }

            for (auto &w : levelVisited) {
                visited.insert(w);
                dict.erase(w);
            }
        }
    }

    void dfs(string word, string beginWord) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto &p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return ans;

        bfs(beginWord, endWord, dict);

        path.push_back(endWord);
        dfs(endWord, beginWord);

        return ans;
    }
};
