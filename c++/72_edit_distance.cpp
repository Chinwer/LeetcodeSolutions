/*
 * 72. Edit Distance
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 *
 * You have the following 3 operations permitted on a word:
 *   1. Insert a character
 *   2. Delete a character
 *   3. Replace a character
 */

#include "header.h"

class Solution {
    private:
        string word1, word2;
        vector<vector<int>> memo;

    public:
        int minDistance(string word1, string word2) {
            this->word1 = word1;
            this->word2 = word2;
            int size1 = word1.size();
            int size2 = word2.size();
            this->memo = vector(size1, vector(size2, -1));
            // return dp(word1.size() - 1, word2.size() - 1);
            // return top_down(size1 - 1, size2 - 1);
            return bottom_up(size1 - 1, size2 - 1);
        }

        int bottom_up(int i, int j) {
            int size1 = word1.size();
            int size2 = word2.size();
            vector<vector<int>> dp(size1 + 1, vector(size2 + 1, 0));
            for (int i = 0; i <= size1; i++) {
                dp[i][0] = i;
            }
            for (int j = 0; j <= size2; j++) {
                dp[0][j] = j;
            }
            for (int i = 1; i <= size1; i++) {
                for (int j = 1; j <= size2; j++) {
                    if (word1[i - 1] == word2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = _min(
                            dp[i][j - 1] + 1,
                            dp[i - 1][j] + 1,
                            dp[i - 1][j - 1] + 1
                        );
                    }
                }
            }
            return dp[size1][size2];
        }

        int top_down(int i, int j) {
            if (i == -1) {
                return j + 1;
            }
            if (j == -1) {
                return i + 1;
            }
            if (memo[i][j] != -1) {
                return memo[i][j];
            }
            if (word1[i] == word2[j]) {
                memo[i][j] = top_down(i - 1, j - 1);
                return memo[i][j];
            }
            memo[i][j] = _min(
                top_down(i, j - 1) + 1,
                top_down(i - 1, j) + 1,
                top_down(i - 1, j - 1) + 1
            );
            return memo[i][j];
        }

        /* return the minimum number of operations
           required to convert word1[0..i] to word[0..j]
                     TIME LIMTT EXCEEDED            */
        int dp(int i, int j) {
            if (i == -1) {
                return j + 1;
            }
            if (j == -1) {
                return i + 1;
            }
            if (word1[i] == word2[j]) {
                return dp(i - 1, j - 1);
            }
            return _min(
                dp(i, j - 1) + 1,
                dp(i - 1, j) + 1,
                dp(i - 1, j - 1) + 1
            );
        }

        int _min(int a, int b, int c) {
            return min(a, min(b, c));
        }
};
