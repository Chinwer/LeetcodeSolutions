/*
 * 212. Word Search II
 *
 * Given a 2D board and a list of words from the dictionary, find all words in the board.
 *
 * Each world must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring.
 * The same letter cell may not be used more than once in a word.
 *
 * Note:
 *   - All inputs are consist of lowercase lettesr a-z.
 *   - The values of words are distinct.
 */

#include "header.h"

class TrieNode {
    public:
        string word;
        TrieNode *next[26] = { nullptr };
};

class Solution {
    private:
        int m, n;
        vector<string> res;
        vector<vector<char>> board;
        int dr[4] = { 0, 0, 1, -1 };
        int dc[4] = { 1, -1, 0, 0 };

    public:
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            m = board.size();
            n = board[0].size();
            if (!m || !n) {
                return res;
            }

            this->board = board;

            TrieNode *root = new TrieNode();
            for (string &w : words) {
                int len = w.size();
                TrieNode *cur = root;
                for (int i = 0; i < len; i++) {
                    int idx = w[i] - 'a';
                    if (!cur->next[idx]) {
                        cur->next[idx] = new TrieNode();
                    }
                    cur = cur->next[idx];
                }
                cur->word = w;
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    dfs(i, j, root);
                }
            }
            return res;
        }

        void dfs(int r, int c, TrieNode *root) {
            char ch = board[r][c];
            int idx = ch - 'a';
            if (!root->next[idx]) {
                return;
            }
            root = root->next[idx];
            if (!root->word.empty()) {
                res.push_back(root->word);
                root->word = "";
            }
            board[r][c] = '.';
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (valid(nr, nc)) {
                    dfs(nr, nc, root);
                }
            }
            board[r][c] = ch;
        }

        bool valid(int r, int c) {
            return 0 <= r && r < m
                && 0 <= c && c < n
                && board[r][c] != '.';
        }
};
