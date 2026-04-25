struct Node{
    Node* links[26];
    bool flag = false;
    // Check karta hai ki kya character 'ch' ka link pehle se bana hai?

    bool containsKey(char ch){
        if(links[ch - 'a'] != NULL) return true;
        else return false;
    }
    // Naya node daalne ke liye

    void put(char ch , Node* node){
        links[ch-'a'] = node;
    }

    // Next node pe jaane ke liye

    Node* get(char ch){
        return links[ch-'a'];
    }
    // Word ko khatam mark karne ke liye

    void setEnd(){
        flag = true;
    }

    // Check karne ke liye ki word yahan khatam hai ya nahi

    bool isEnd(){
        return flag;
    }

};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;

        for(int i = 0 ; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i] , new Node());
            }


            node =node->get(word[i]);

        }

        node->setEnd();
    }
    
    bool search(string word) {
        Node*  node = root;

        for(int i = 0 ; i < word.size() ; i++){
            if(!node->containsKey(word[i])){
                return false;
            }

            node = node->get(word[i]);
        }

        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0 ; i < prefix.size() ; i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }

            node = node->get(prefix[i]);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */