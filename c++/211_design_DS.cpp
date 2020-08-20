/*
 * 211. Design Add and Search Words Data Structure
 *
 * You should design a data structure that supports adding new words
 * and finding if a string matches any previously added string.
 *
 * Implement the WordDictionary class:
 *
 * WordDictionary() Initializes the object.
 * void addWord(word) adds word to the data structure, it can be matched later.
 * bool search(word) returns true if there is any string in the data
 * structure that matches word or false otherwise. word may contain dots
 * '.' where dots can be matched with any letter.
 *
 * Constraints:
 *   - 1 <= word.length <= 500
 *   - word in addWord consists lower-case English letters.
 *   - word in search consist of  '.' or lower-case English letters.
 *   - At most 50000 calls will be made to addWord and search .
 */

#include "header.h"

class WordDictionary {
    private:
        bool is_end = false;
        WordDictionary *next[26] = { nullptr };

    public:
        /** Initialize your data structure here. */
        WordDictionary() {}

        /** Adds a word into the data structure. */
        void addWord(string word) {
            WordDictionary *node = this;
            for (const char &c : word) {
                int idx = c - 'a';
                if (!node->next[idx]) {
                    node->next[idx] = new WordDictionary();
                }
                node = node->next[idx];
            }
            node->is_end = true;
        }

        /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
        bool search(string word) {
            return search(this, word);
        }

        bool search(WordDictionary *node, string &word) {
            int n = word.length();
            for (int i = 0; i < n; i++) {
                if (word[i] == '.') {
                    for (int j = 0; j < 26; j++) {
                        string sub = word.substr(i + 1);
                        if (node->next[j] && search(node->next[j], sub)) {
                            return true;
                        }
                    }
                    return false;
                }
                int idx = word[i] - 'a';
                if (!node->next[idx]) {
                    return false;
                }
                node = node->next[idx];
            }
            return node->is_end;
        }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
