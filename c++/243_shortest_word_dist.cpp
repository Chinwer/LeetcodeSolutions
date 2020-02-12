/*
 * 243. Shortest Word Distance
 * Given a list of words and two words word1 and word2, return the shortest
 * distance between these two words in the list.
 *
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2
 * are both in the list.
 */

#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        int shortestDistance(vector<string>& words, string word1, string word2) {
            int idx1 = -1;
            int idx2 = -1;
            int size = words.size();
            int res = size;
            for (int i = 0; i < size; i++) {
                if (words[i] == word1) {
                    idx1 = i;
                } else if (words[i] == word2) {
                    idx2 = i;
                }
                if (idx1 != -1 && idx2 != -1) {
                    res = min(res, abs(idx1 - idx2));
                }
            }
            return res;
        }
};
