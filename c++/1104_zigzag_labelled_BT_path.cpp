/*
 * 1104. Path In Zigzag Labelled Binary Tree
 *
 * In an infinite binary tree where every node has two children,
 * the nodes are labelled in row order.
 *
 * In the odd numbered rows (ie., the first, third, fifth,...),
 * the labelling is left to right, while in the even numbered rows
 * (second, fourth, sixth,...), the labelling is right to left.
 *
 * Given the label of a node in this tree, return the labels in the
 * path from the root of the tree to the node with that label.
 *
 * Constraints:
 *
 * 1 <= label <= 10^6
 */

#include "header.h"

class Solution {
    public:
        vector<int> pathInZigZagTree(int label) {
            vector<int> res;
            int level = log(label) / log(2) + 1;
            while (label > 1) {
                res.push_back(label);
                label = (3 * (1 << (--level)) - label / 2 - 1);
            }
            res.push_back(1);
            reverse(res.begin(), res.end());
            return res;
        }
};
