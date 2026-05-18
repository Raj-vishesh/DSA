#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        child[0] = child[1] = NULL;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

  
    void insert(int num) {
        TrieNode* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (node->child[bit] == NULL) {
                node->child[bit] = new TrieNode();
            }

            node = node->child[bit];
        }
    }

   
    int getMaxXOR(int num) {
        TrieNode* node = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

     
            int toggledBit = 1 - bit;

            if (node->child[toggledBit] != NULL) {
                maxXor |= (1 << i);
                node = node->child[toggledBit];
            } else {
                node = node->child[bit];
            }
        }

        return maxXor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;

        
        for (int num : nums) {
            trie.insert(num);
        }

        int ans = 0;

       
        for (int num : nums) {
            ans = max(ans, trie.getMaxXOR(num));
        }

        return ans;
    }
};