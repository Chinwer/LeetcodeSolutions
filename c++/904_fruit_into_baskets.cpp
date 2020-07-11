/*
 * 904. Fruit Into Baskets
 *
 * In a row of trees, the i-th tree produces fruit with type tree[i].
 * You start at any tree of your choice, then repeatedly perform the following steps:
 * Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
 * Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
 * Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.
 * You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.
 * What is the total amount of fruit you can collect with this procedure?
 *
 * Note:
 * 1 <= tree.length <= 40000
 * 0 <= tree[i] < tree.length
 */

#include "header.h"

class Solution {
    public:
        int totalFruit(vector<int>& tree) {
            map<int, int> cnt;
            int size = tree.size();
            int res = 0, slow = 0, fast = 0;

            while (fast < size) {
                cnt[tree[fast]]++;
                while (cnt.size() >= 3) {
                    cnt[tree[slow]]--;
                    if (!cnt[tree[slow]]) {
                        cnt.erase(tree[slow]);
                    }
                    slow++;
                }
                res = max(res, fast - slow + 1);
                fast++;
            }
            return res;
        }
};
