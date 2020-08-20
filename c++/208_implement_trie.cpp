/*
 * 208. Implement Trie (Prefix Tree)
 *
 * Implement a trie with insert, search, and starsWith methods.
 *
 * Note:
 *   - You may assume that all inputs are consist of lowercase letters.
 *   - All inputs are guaranteed to be non-empty strings.
 */

#include "header.h"

class Trie {
    private:
        bool is_end = false;
        Trie *next[26] = { nullptr };

    public:
        /** Initialize your data structure here. */
        Trie() {}

        /** Inserts a word into the trie. */
        void insert(string word) {
            Trie *node = this;
            for (const char &c : word) {
                int idx = c - 'a';
                if (!node->next[idx]) {
                    node->next[idx] = new Trie();
                }
                node = node->next[idx];
            }
            node->is_end = true;
        }

        /** Returns if the word is in the trie. */
        bool search(string word) {
            Trie *node = this;
            for (const char &c : word) {
                node = node->next[c - 'a'];
                if (!node) {
                    return false;
                }
            }
            return node->is_end;
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            Trie *node = this;
            for (const char &c : prefix) {
                node = node->next[c - 'a'];
                if (!node) {
                    return false;
                }
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
