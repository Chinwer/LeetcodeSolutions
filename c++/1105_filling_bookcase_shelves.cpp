/*
 * 1105. Filling Bookcase Shelves
 *
 *
 * We have a sequence of books: the i-th book has thickness
 * books[i][0] and height books[i][1].
 *
 * We want to place these books in order onto bookcase shelves that
 * have total width shelf_width.
 *
 * We choose some of the books to place on this shelf (such that the
 * sum of their thickness is <= shelf_width), then build another level of
 * shelf of the bookcase so that the total height of the bookcase has
 * increased by the maximum height of the books we just put down.
 * We repeat this process until there are no more books to place.
 *
 * Note again that at each step of the above process, the order of the
 * books we place is the same order as the given sequence of books.
 * For example, if we have an ordered list of 5 books, we might place
 * the first and second book onto the first shelf, the third book on the
 * second shelf, and the fourth and fifth book on the last shelf.
 *
 * Return the minimum possible height that the total bookshelf can be
 * after placing shelves in this manner.
 *
 * Constraints:
 *
 * 1 <= books.length <= 1000
 * 1 <= books[i][0] <= shelf_width <= 1000
 * 1 <= books[i][1] <= 1000
 */

#include "header.h"

class Solution {
    public:
        int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
            int n = books.size();
            vector<int> dp(n + 1, INT_MAX);
            dp[0] = 0;
            for (int i = 1; i <= n; i++) {
                int j = i, width = 0, max_height = 0;
                while (j > 0) {
                    width += books[j - 1][0];
                    if (width > shelf_width) {
                        break;
                    }
                    max_height = max(max_height, books[j - 1][1]);
                    dp[i] = min(dp[i], dp[j - 1] + max_height);
                    j--;
                }
            }
            return dp[n];
        }
};
