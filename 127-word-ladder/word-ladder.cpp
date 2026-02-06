class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin() , wordList.end());

        if(st.find(endWord) == st.end()){
            return 0;
        }

        queue<pair<string , int>> q;

        q.push({beginWord , 1});
        st.erase(beginWord);

        while(!q.empty()){
            auto front = q.front();
            q.pop();


            string word  = front.first;
            int level =  front.second;

            if(word == endWord){
                return level;
            }

            for(int i = 0 ; i < word.size(); i++){
                char org = word[i];
                

                for(char ch = 'a' ; ch <= 'z' ; ch++){

                    if(ch == org ) continue;
                    word[i] = ch;

                    if(st.find(word) != st.end()){
                        q.push({word , level+1});
                        st.erase(word);
                    }
                }

                word[i] = org;
            }
        }

        return 0;
        
    }
};