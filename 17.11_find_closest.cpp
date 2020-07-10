/*
 * 面试题17.11.Find Closest LCCI
 *
 *
 * You have a large text file containing words.
 * Given any two words, find the shortest distance (in terms of number of words) between them in the file.
 * If the operation will be repeated many times for the same file (but different pairs of words), can you optimize your solution?
 *
 * Note:
 * words.length <= 100000
 */

#include "header.h"

class Solution {
    public:
        int findClosest(vector<string>& words, string word1, string word2) {
            // int size = words.size();
            // map<string, vector<int>> hash;
            // for (int i = 0; i < size; i++) {
            //     hash[words[i]].push_back(i);
            // }

            // vector<int> pos1 = hash[word1];
            // vector<int> pos2 = hash[word2];

            // // find the minimum distance between pos1 and pos2
            // int res = INT_MAX, ptr1 = 0, ptr2 = 0;
            // int size1 = pos1.size(), size2 = pos2.size();
            // while (ptr1 < size1 && ptr2 < size2) {
            //     if (pos1[ptr1] < pos2[ptr2]) {
            //         res = min(res, pos2[ptr2] - pos1[ptr1]);
            //         ptr1++;
            //     } else {
            //         res = min(res, pos1[ptr1] - pos2[ptr2]);
            //         ptr2++;
            //     }
            // }
            // return res;

            /* optimized version */
            int res = INT_MAX;
            int ptr1 = -100000, ptr2 = 100000, size = words.size();
            for (int i = 0; i < size; i++) {
                bool new_pos = false;
                if (words[i] == word1) {
                    new_pos = true;
                    ptr1 = i;
                } else if (words[i] == word2) {
                    new_pos = true;
                    ptr2 = i;
                }
                if (new_pos) {
                    res = min(res, abs(ptr2 - ptr1));
                }
            }
            return res;
        }
};
